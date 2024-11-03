#include "HackerRank.hh"
#include "StringChallenges.hh"

#include <iostream>
#include <vector>
#include <cstring>


int main() {

    std::vector<std::vector<int>> vec = {
        {112, 42, 83, 119},
        {56, 125, 56, 49},
        {15, 78, 101, 43},
        {62, 98, 114, 108}
    };

    std::vector<std::vector<int>> new_vec = {
        {811, 2137},
        {2904, 107}
    };

    int result = flippingMatrix(new_vec);

    return 0;
}


