#include "LeetCode.hh" 
#include <set>


bool isValidSudoku(std::vector<std::vector<char>>& board) {
    
    std::set<char> items;

    for (auto& row : board) {
        for (auto& num : row) {
            if (num == '.')
                continue;
            if (items.find(num) == items.end()) { // item not found
                items.insert(num);
            } else {
                return false; 
            }
        }
        items.clear();
    }


    for (int column=0; column < board.size(); column++) {
        for (int row = 0; row < board.size(); row++) {
            if (board[row][column] == '.')
                continue;
            if (items.find(board[row][column]) == items.end()) { // item not found
                items.insert(board[row][column]);
            } else {
                return false; 
            }
        }
        items.clear();
    }

    for (int block_x = 0; block_x < board.size(); block_x+=3) {
        for (int block_y = 0; block_y < board.size(); block_y+=3) {

            int x_bounds = block_x + 3;
            int y_bounds = block_y + 3;

            for (int row = block_x; row<x_bounds; row++) {
                for (int column = block_y; column<y_bounds; column++) {
                    if (board[column][row] == '.')
                        continue;
                    if (items.find(board[column][row]) == items.end()) {
                        items.insert(board[column][row]);
                    } else {
                        return false;
                    }
                }
            }
            items.clear();
        }
    }


    return true;
}

