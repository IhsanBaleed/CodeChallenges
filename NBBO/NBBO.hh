#pragma once

#include <string>
#include <map>
#include <limits>
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sstream>
#include <vector>

// Notice how only the most recent quote from each exchange matters for calculating the NBBO.
// calculator. Your program will need to connect to the exchange-simulator to receive a stream of quotes.
// The goal is to write the fastest, most efficient NBBO calculator possible.
// handle as many symbols from as many exchanges as fast as possible.
// It is already running, listening for connections on port 7777. Once you connect, it will start sending you quotes.
// The exchange-simulator will print the current NBBO
// It will send quotes for only two symbols (DELL and IBM) on two different exchanges (BATS and NASDAQ)

struct quote {
    std::string stock_name;
    std::string market;
    double bid;
    double offer;
};

class Stock {
    
    std::string stock_name;
    double bid = 0;
    double offer = 0;

    // market - {bid - offer}
    std::map<std::string, std::pair<double,double>> markets;

    void update_nbbo() {
        double max_bid = std::numeric_limits<double>::min();
        double min_offer = std::numeric_limits<double>::max();
        
        for (auto& market : markets) {
            max_bid = std::max(max_bid, market.second.first);
            min_offer = std::min(min_offer, market.second.second);
        }
        bid = max_bid;
        offer = min_offer;
    }

public:

    Stock(std::string name) : stock_name(name) {}

    void update_markets(std::string market, double bid, double offer) {
        if (markets.find(market) == markets.end()) {
            markets[market] = {bid, offer};
        } else {
            markets[market].first = bid;
            markets[market].second = offer;
        }
        update_nbbo();
    }

    void print_stock() {
        std::cout << stock_name << " Bid=" << bid << " @ Offer=" << offer << std::endl;
    }
};

class NBBOSocket {

    int sock;
    std::string ip;
    int port;

    void close_socket() {
        close(sock);
    }

public:

    NBBOSocket(std::string ip, int port) : ip(ip), port(port){}

    ~NBBOSocket() {
        close_socket();
    }

    void connect_to_server() {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            std::cerr << "Error creating socket" << std::endl;
            exit(1);
        }

        struct sockaddr_in server_addr;
        std::memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

        // Connect to the server
        if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            std::cerr << "Error connecting to server" << std::endl;
            close_socket();
            exit(1);
        }
        std::cout << "Connected to server" << std::endl;
    }

    std::string receive_data() {
        char buffer[2048];
        std::memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received < 0) {
            std::cerr << "Error receiving data" << std::endl;
            close_socket();
            exit(1);
        } else if (bytes_received == 0) {
            std::cout << "Server closed the connection" << std::endl;
            close_socket();
            exit(1);
        }
        std::cout << "Received: " << buffer << std::endl;
        return buffer;
    }
};

class Parser {

public:

    bool is_quote(std::string input) {
        return (input.size()>1 && input.substr(0,2) == "Q-");
        return false;
    }

    std::vector<quote> get_quotes(std::istringstream& stream) {
        std::vector<quote> quotes;
        std::string line;
        while (std::getline(stream, line)) {
            if (is_quote(line)) {

                size_t pos1 = line.find('-');
                size_t pos2 = line.find('-', pos1 + 1);
                size_t pos3 = line.find('-', pos2 + 1);
                size_t pos4 = line.find('-', pos3 + 1);

                std::string stock = line.substr(pos1 + 1, pos2 - pos1 - 1);
                std::string market = line.substr(pos2 + 1, pos3 - pos2 - 1);
                double bid = std::stod(line.substr(pos3 + 1, pos4 - pos3 - 1));
                double offer = std::stod(line.substr(pos4 + 1));

                quote q = {
                    stock,
                    market,
                    bid,
                    offer,
                };
                quotes.push_back(q);
            }
        }

        return quotes;
    }
};

void update_stocks(std::vector<quote> q, std::map<std::string, Stock>& stocks) {
    for (auto& item : q) {
        if (stocks.find(item.stock_name) == stocks.end()) {
            Stock s(item.stock_name);
            s.update_markets(item.market, item.bid, item.offer);
            stocks.emplace(item.stock_name, s);
        } else {
            stocks.find(item.stock_name)->second.update_markets(item.market, item.bid, item.offer);
        }
    }
}

void display_stocks(std::map<std::string, Stock>& stocks) {
    std::cout << "NBBO Latest ----------------" << std::endl;  
    for (auto& stock : stocks) {
        stock.second.print_stock();
    }
    std::cout << std::endl;
}

void nbbo_driver_code() {
    std::map<std::string, Stock> stocks;

    NBBOSocket socket("127.0.0.1", 7777);
    socket.connect_to_server();

    while (true) {
        std::istringstream stream(socket.receive_data());

        Parser p;
        update_stocks(p.get_quotes(stream), stocks);
        display_stocks(stocks);
    }
}

