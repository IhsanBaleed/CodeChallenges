#pragma once
#include <vector>
#include <string>
#include <iostream>

int median(int size, int* arr);

std::vector<int> mergeLists(std::vector<int> list1, std::vector<int> list2);

int flippingMatrix(std::vector<std::vector<int>>matrix);

void read_stdin() {
    for (std::string line; std::getline(std::cin, line);) {
        std::cout << line << std::endl;
    }
}

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

