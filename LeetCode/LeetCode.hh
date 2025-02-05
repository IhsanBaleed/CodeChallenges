#pragma once
#include <vector>


bool isValidSudoku(std::vector<std::vector<char>>& board);

class Node {
public:
  int val;
  Node* next;
  Node( int _val, Node* _next ) : val( _val ), next( _next ) {};
  Node( int _val ) : val( _val ), next( nullptr ) {};
  Node() : val( 0 ), next( nullptr ) {};
};

Node* mergeTwoLists(Node* list1, Node* list2);

void test_char_ptr(const char* str1, const char* str2);
