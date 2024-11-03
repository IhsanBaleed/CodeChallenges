#include "HackerRank.hh"

#include <map>

int median(int size, int* arr) {
    if (size == 1) {
        return arr[0];
    }
    for (int i=0; i <size; i++) {
        for (int j=i+1; j<size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr[size/2];
}

std::vector<int> mergeLists(std::vector<int> list1, std::vector<int> list2) {

    std::vector<int> result;
    bool got_all_items = false;

    int list1_index = 0;
    int list2_index = 0;

    while (!got_all_items) {

        if(list1_index == list1.size() && list2_index == list2.size()) {
            break;
        }
        if (list1_index < list1.size() && list2_index < list2.size()) {
            if(list1[list1_index] < list2[list2_index]){
                result.push_back(list1[list1_index++]);
            } else {
                result.push_back(list2[list2_index++]);
            }
            continue;
        }
        if (list1_index == list1.size()) {
            result.push_back(list2[list2_index++]);
            continue;
        }
        if (list2_index == list2.size()) {
            result.push_back(list1[list1_index++]);
            continue;
        }
    }
    return result;
}

int flippingMatrix(std::vector<std::vector<int>>matrix) {
    int result = 0;
    int n = matrix.size()/2;
    int row_max_index = n*2-1;

    std::map<std::pair<int,int>, int> max_val_map;

    for (int i=0; i < n; i ++)
        for (int j=0; j<n; j++)
            max_val_map.emplace(std::make_pair(i,j), matrix[i][j]);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            std::pair<int, int> key = std::make_pair(i, j);

            if (max_val_map[key] < matrix[i][row_max_index-j]) {
                max_val_map[key] = matrix[i][row_max_index-j];
            }
            if (max_val_map[key] < matrix[row_max_index-i][j]) {
                max_val_map[key] = matrix[row_max_index-i][j];
            }
            if (max_val_map[key] < matrix[row_max_index-i][row_max_index-j]) {
                max_val_map[key] = matrix[row_max_index-i][row_max_index-j];
            }
        }
    }

    for (auto& point : max_val_map) {
        result += point.second;
    }
    
    return result;

}
