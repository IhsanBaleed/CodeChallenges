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

std::vector<int> minimalOperations(std::vector<std::string> words) {

    std::vector<int> result;

    for (auto& word : words) {
        int operations = 0;
        for (int i=0; i<word.size()-1; i++) {
            if (word.at(i) == word.at(i+1)) {
                word.at(i+1) = '#';
                operations++;
            }
        }
        result.push_back(operations);
    }
    return result;
}

long getMaximumSumOfStrengths(std::vector<int> arr) {

    long result = 0;

    for (int i=0; i<arr.size()-1;) {
        if (arr[i] > arr[i+1]) {

            if (i < arr.size()-2 && arr[i+1] > arr[i+2]) { // if 3ed item is smaller than second
                int sum1 = arr[i]*(i+1) + arr[i+2]*(i+2) + arr[i+1]*(i+3); // swap second and third
                int sum2 = arr[i+1]*(i+1) + arr[i]*(i+2) + arr[i+2]*(i+3); // swap first and second
                
                if (sum1 > sum2) { // if yes, skip to next item
                    i++;
                } else if (sum1 < sum2) { 
                    int temp = arr[i+1];
                    arr[i+1] = arr[i];
                    arr[i] = temp;
                    i+=2;
                } else
                    i++;
            } else {
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                i+=2;
            }

        } else 
            i++;
    }

    for (int i=0; i<arr.size(); i++) {
        result += arr[i] * (i+1);
    }

    return result;
}

void generatePermutations(std::vector<int>& arr, int index, int m, std::vector<std::vector<int>>& permutations) {
    if (index == arr.size()) {
        permutations.push_back(arr);
        return;
    }

    if (arr[index] == -1) {
        for (int num = 1; num <= m; ++num) {
            arr[index] = num;
            generatePermutations(arr, index + 1, m, permutations);
            arr[index] = -1;
        }
    } else {
        generatePermutations(arr, index + 1, m, permutations);
    }
}

std::vector<std::vector<int>> getAllPermutations(std::vector<int> arr, int m) {
    std::vector<std::vector<int>> permutations;
    generatePermutations(arr, 0, m, permutations);
    return permutations;
}

int countWaysToCreateWave(std::vector<int> arr, int m) {

    std::vector<std::vector<int>> waves = getAllPermutations(arr, m);

    int result = 0;

    for (auto wave : waves) { // sin wave
        for (int i=0; i<wave.size()-1; i++) {
            if (i%2==0 && wave[i] <= wave[i+1]) {
                break;
            }
            if (i%2==1 && wave[i] >= wave[i+1]) {
                break;
            }
            if (i==wave.size()-2) {
                result ++;
            }
        }
    }

    for (auto wave : waves) { // cos wave
        for (int i=0; i<wave.size()-1; i++) {
            if (i%2==0 && wave[i] >= wave[i+1]) {
                break;
            }
            if (i%2==1 && wave[i] <= wave[i+1]) {
                break;
            }
            if (i==wave.size()-2) {
                result ++;
            }
        }
    }

    return result;
}


