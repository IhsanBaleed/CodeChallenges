#include "HackerRank.hh"

#include <map>
#include <set>
#include <cctype>

int median(int size, int* arr) {
    if (size == 1) {
        return arr[0];
    }
    for (int i=0; i <size; i++) {
        for (int j=i+1; j<size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr[size/2];
}

std::vector<int> mergeLists(std::vector<int> list1, std::vector<int> list2) {

    std::vector<int> result;
    bool got_all_items = false;

    int list1_index = 0;
    int list2_index = 0;

    while (!got_all_items) {

        if(list1_index == list1.size() && list2_index == list2.size()) {
            break;
        }
        if (list1_index < list1.size() && list2_index < list2.size()) {
            if(list1[list1_index] < list2[list2_index]){
                result.push_back(list1[list1_index++]);
            } else {
                result.push_back(list2[list2_index++]);
            }
            continue;
        }
        if (list1_index == list1.size()) {
            result.push_back(list2[list2_index++]);
            continue;
        }
        if (list2_index == list2.size()) {
            result.push_back(list1[list1_index++]);
            continue;
        }
    }
    return result;
}

int flippingMatrix(std::vector<std::vector<int>>matrix) {

    if (matrix.size() == 1) {
        return matrix[0][0];
    }

    int result = 0;
    int n = matrix.size()/2;
    int row_max_index = n*2-1;

    std::map<std::pair<int,int>, int> max_val_map;

    for (int i=0; i < n; i ++)
        for (int j=0; j<n; j++)
            max_val_map.emplace(std::make_pair(i,j), matrix[i][j]);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            std::pair<int, int> key = std::make_pair(i, j);

            if (max_val_map[key] < matrix[i][row_max_index-j]) {
                max_val_map[key] = matrix[i][row_max_index-j];
            }
            if (max_val_map[key] < matrix[row_max_index-i][j]) {
                max_val_map[key] = matrix[row_max_index-i][j];
            }
            if (max_val_map[key] < matrix[row_max_index-i][row_max_index-j]) {
                max_val_map[key] = matrix[row_max_index-i][row_max_index-j];
            }
        }
    }

    for (auto& point : max_val_map) {
        result += point.second;
    }
    
    return result;

}

void editor_main() {
    std::string current_text;
    TextHistory history(current_text);

    for (std::string line; std::getline(std::cin, line);) {

        char command = line.at(0);
        std::string data;
        if (line.size() > 2) {
            data = line.substr(2);
        }

        switch (command) {

            case '1': {
                current_text += data;
                history.push(current_text);
                break;
            }

            case '2': {
                int chars = std::stoi(data);
                current_text.erase(current_text.size() - chars);
                history.push(current_text);
                break;
            }

            case '3': {
                int index = std::stoi(data);
                std::cout << current_text.at(index-1) << std::endl;
                break;
            }

            case '4':  {
                history.pop();
                current_text = history.current_val();
                break;
            }
        }
    }
}

std::string caesarCipher(std::string s, int k) {

    std::string result = "";

    for (auto letter : s) {
        
        if (isalpha(letter)) {
            int asci_val = static_cast<int>(letter);
            if(asci_val >=97 && asci_val + k > 122) {                
                int letter_val = static_cast<int>('a') + (asci_val + k - 122) -1;
                result += static_cast<char>(letter_val);
            } else if (asci_val <= 90 && asci_val + k > 90)  {
                int letter_val = static_cast<int>('A') + (asci_val + k - 90) -1;
                result += static_cast<char>(letter_val);
            } else {
                letter +=k;
                result += letter;
            }

        } else {
            result += letter;
        }
    }
    return result;
}

int superDigit(std::string n, int k) {
    
    std::string base = n;
    while (k > 1) {
        n += base;
        k--;
    }
    
    long long  digit = std::stol(n);
    
    if (digit < 10) {
        return digit;
    } else {
        long long total = 0;
        for (auto val : n) {
            total += val - '0';
        }
        return superDigit(std::to_string(total), k);
    }
}

std::string gridChallenge(std::vector<std::string> grid) {
    
    for (auto &row : grid) {
        for (int i=0; i<row.size(); i++) {
            for (int j=i+1; j <row.size(); j++) {
                if(row[i] > row[j]) {
                    char temp = row[i];
                    row[i] = row[j];
                    row[j] = temp;
                }
            }
        }  
    }

    for (int c=0; c<grid.size(); c++ ) {
        for (int i=0; i < grid.size()-1; i++) {

            if (grid[i].at(c) > grid[i+1].at(c)) {  
                return "NO";
            }
        
        }
    }

    return "YES";
}

void minimumBribes(std::vector<int> q) {

    int bribes=0;
    int n=q.size();
    //int i=0;
    for(int i=0;i<n;i++){
        if(q[i]>(i+1+2)){
            std::cout << "Too chaotic" << std::endl;
            return;
        }
        //else if(q[i]==i+1){continue;}
        
        for (int j = std::max(0, q[i] - 2); j < i; j++)
            if (q[j] > q[i]) bribes++;
        
    }
    std::cout << bribes << std::endl;

}

int truckTour(std::vector<std::vector<int>> petrolpumps) {

    int fuel = 0;
    int distance = 1;
    int required_stations = petrolpumps.size();

    for (int station = 0; station < petrolpumps.size(); station++) {
        int tank = 0;
        int total_visited_stations = 0;

        if (petrolpumps[station][fuel] + tank - petrolpumps[station][distance] < 0) {
            continue;
        }

        tank += petrolpumps[station][fuel] - petrolpumps[station][distance];
        total_visited_stations++;

        int next_station = station;
        
        while (total_visited_stations < required_stations) {
            next_station++;

            if (next_station == petrolpumps.size()) {
                next_station = 0;
            }

            if (petrolpumps[next_station][fuel] + tank - petrolpumps[next_station][distance] < 0) {
                break;
            }

            tank += petrolpumps[next_station][fuel] - petrolpumps[next_station][distance];
            total_visited_stations++;
        }

        if (total_visited_stations == required_stations) {
            return station;
        }
    }
    return 0;
}

std::string isBalanced(std::string s) {

    // you can use a stack to make it work,
    // push the openning brackets, and pop when you get a closing one of the same type.
    int processed_items = 0;

    if (s.size() % 2 == 1) 
        return "NO";
  
    for (int i=0; i<s.size()-1; i++) {
        int jump = 0;
        char val_at_i = s.at(i);

        char target;
        switch (val_at_i) {
            case '(':
                    target = ')';
                break;
            case '{':
                    target = '}';
                break;
            case '[':
                    target = ']';
                break;
            default:
                continue;
        }

        for (int j=i+1; j < s.size(); j++) {
            char val_at_j = s.at(j);

            if (val_at_j == val_at_i) {
                jump++;
                continue;
            }

            if (target == s.at(j)) {
                if (jump > 0) {
                    jump --;
                    continue;
                } else {
                    if ((j - i - 1) % 2 == 1) {
                        return "NO";
                    }
                    processed_items += 2;
                    break;
                }
            }
 
        }
    }

    if (processed_items == s.size()) {
        return "YES";
    }
    return "NO";

}



