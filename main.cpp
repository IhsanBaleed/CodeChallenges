#include "HackerRank.hh"
#include "StringChallenges.hh"
#include "Arrays.hh"

#include <iostream>
#include <vector>
#include <cstring>


int main() {

    // int result = legoBlocks(2, 3);

    std::vector<std::vector<int>> edges;

    std::vector<int> edge_1 = {2,3};
    // std::vector<int> edge_2 = {2,3};
    // std::vector<int> edge_3 = {2,5};
    // std::vector<int> edge_4 = {5,6};

    edges.push_back(edge_1); 
    // edges.push_back(edge_2); 
    // edges.push_back(edge_3);
    // edges.push_back(edge_4);

    std::vector<int> result = bfs(3, 1, edges, 2);

    print_array(result);

    return 0;
}



