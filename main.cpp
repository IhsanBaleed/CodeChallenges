#include "HackerRank.hh"
#include "StringChallenges.hh"
#include "Arrays.hh"
#include "CodeWars.hh"

#include <iostream>
#include <vector>
#include <cstring>



int main() {

    std::string str_1 = "1, 3, 4, 7, 13";
    std::string str_2 = "1, 2, 4, 13, 15";

    std::string strArr[] = {str_1, str_2};
 
    FindIntersection(strArr, 2);
    return 0;
}



