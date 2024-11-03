#pragma once
#include <string>
#include <vector>



std::string unmix(std::string str);

int findZip(std::string str);

std::string extendVowels(std::string word, int num);

std::string toCamelCase(std::string str);

std::string toSnakeCase(std::string str);

std::vector<int> move_zeroes(const std::vector<int>& input);

int ware_house_locations(int stores, int* locations, long d);

int rate_limit(int n, char* input_ptr, int min_gap);

int median(int size, int* arr);
