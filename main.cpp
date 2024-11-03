#include "HackerRank.hh"
#include "StringChallenges.hh"

#include <iostream>
#include <vector>
#include <cstring>


int main() {

    std::string str = "abacadaeafag";
    char* data = new char[str.length() + 1];
    std::strcpy(data, str.c_str());

    int size = 12;
    int min_gap = 2;
    
    int result = rate_limit(size, data, min_gap);
    return 0;
}


