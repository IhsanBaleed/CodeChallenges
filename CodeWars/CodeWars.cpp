#include "CodeWars.hh"

int multiple_3_5(int val) {
    if (val < 0) {
        return 0;
    }

    int result = 0;

    for (int i=1; i < val; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            result += i;
        }
    }
    
    return result;
}

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {    

    std::vector<int> result;

    if (snail_map.size() == 1 && snail_map[0].size()== 0) {
        return result;
    }


    bool working = true;
    
    int lhs_index = 0;
    int rhs_index = snail_map.size() - 1;

    int top_row_index = 0;
    int bottom_row_index = snail_map.size()-1;

    while (working) {
                
        for (int i=lhs_index; i<=rhs_index; i++) {
            result.push_back(snail_map[top_row_index][i]);
        }
        top_row_index++;

        for (int j=top_row_index; j<= bottom_row_index; j++) {
           result.push_back(snail_map[j][rhs_index]);
        }
        rhs_index --;

        for (int x=rhs_index; x>= lhs_index; x--) {
            result.push_back(snail_map[bottom_row_index][x]);
        }
        bottom_row_index --;

        for (int y=bottom_row_index; y>=top_row_index; y--) {
            result.push_back(snail_map[y][lhs_index]);
        }
        lhs_index++;

        if (top_row_index > bottom_row_index) {
            break;
        }
    }

    return result;
}

