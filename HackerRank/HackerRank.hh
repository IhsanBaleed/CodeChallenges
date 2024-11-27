#pragma once
#include <vector>
#include <string>
#include <iostream>

int median(int size, int* arr);

std::vector<int> mergeLists(std::vector<int> list1, std::vector<int> list2);

int flippingMatrix(std::vector<std::vector<int>>matrix);

class TextHistory {

    std::string history[100];
    int stack_index = -1;

public:
    TextHistory(std::string text) {
        history[++stack_index] = text;
    }

    std::string pop() {
        if (stack_index < 0) {
            return  "";
        }
        return history[stack_index--];
    }

    void push(std::string data) {
        history[++stack_index] = data;
    }

    std::string current_val() {
        if (stack_index < 0) {
            return  "";
        }
        return history[stack_index];
    }

};

void editor_main();

std::string caesarCipher(std::string s, int k);

inline void read_input() {
    for (std::string line; std::getline(std::cin, line);) {
        std::cout << line << std::endl;
    }
}

int superDigit(std::string n, int k);

std::string gridChallenge(std::vector<std::string> grid);

void minimumBribes(std::vector<int> q);

int truckTour(std::vector<std::vector<int>> petrolpumps);

std::string isBalanced(std::string s);

int pairs(int k, std::vector<int> arr);

int cookies(int k, std::vector<int> A) ;

int legoBlocks(int n, int m);

std::vector<int> bfs(int n, int m, std::vector<std::vector<int>> edges, int s);

void print_array(std::vector<int> arr);

std::string encryption(std::string s);

std::vector<int> breakingRecords(std::vector<int> scores);

int migratoryBirds(std::vector<int> arr);

int getMinimumCost(int k, std::vector<int> c);

int minimumNumber(int n, std::string password);


