#include <iostream>
#include "StringChallenges.hh"
#include <vector>


int main() {

    // int stores = 4;
    // int centres[] = {2, 3, 0, -4};
    // long d = 22;
    // int result = ware_house_locations(stores, centres, d);

    int n = 14;
    char * requests = "aaaaacggtffrrd";
    // char * requests = "abacadaeafag";
    int minGap = 3;

    rate_limit(n, requests, minGap);
    return 0;
}


