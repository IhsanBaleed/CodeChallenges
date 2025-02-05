#include "LeetCode.hh" 
#include <set>
#include <string>


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

Node* mergeTwoLists( Node* list1, Node* list2 ) {

  Node* root = new Node(); // you can also allocate the root on the stack (use normal Node object)
                           // then have the curr point to its next and iterate
                           // make sure to return root->next in that case
  Node* curr = root;
  
  while (list1 != nullptr || list2 != nullptr ) {
    
    if (list1 == nullptr) {
      curr->next = new Node(list2->val);
      curr = curr->next;
      list2 = list2->next;
      continue;
    }
    if (list2 == nullptr) {
      curr->next = new Node(list1->val);
      curr = curr->next;
      list1 = list1->next;
      continue;
    }
    if (list1->val < list2->val) {
      curr->next = new Node(list1->val);
      curr = curr->next;
      list1 = list1->next;
      continue;
    } else {
      curr->next = new Node(list2->val);
      curr = curr->next;
      list2 = list2->next;
      continue;
    }
  }

  curr = root->next;
  delete root;

  return curr;
}

void test_char_ptr(const char* str1, const char* str2) {

    std::string res;

    int i=0; // if i goes out of bounds for an array
             // then we might access garbage values
             // if i is set to size, then we get null terminator '\0'

    while (str1[i] != '\0' || str2[i] != '\0') {
        char l1(str1[i]); 
        char l2(str2[i]);

        if (str1[i] == '\0') {
            break;
        }

        res += l1 + l2;
        
        i++;
    }
    
}

