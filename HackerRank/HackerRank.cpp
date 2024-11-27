#include "HackerRank.hh"

#include <map>
#include <set>
#include <cctype>
#include <numeric>
#include <algorithm>
#include <cmath>

void print_array(std::vector<int> arr) {
    for (auto entry: arr) {
        std::cout << "Entry = " << entry << std::endl;
    }
}

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

    if (matrix.size() == 1) {
        return matrix[0][0];
    }

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

void editor_main() {
    std::string current_text;
    TextHistory history(current_text);

    for (std::string line; std::getline(std::cin, line);) {

        char command = line.at(0);
        std::string data;
        if (line.size() > 2) {
            data = line.substr(2);
        }

        switch (command) {

            case '1': {
                current_text += data;
                history.push(current_text);
                break;
            }

            case '2': {
                int chars = std::stoi(data);
                current_text.erase(current_text.size() - chars);
                history.push(current_text);
                break;
            }

            case '3': {
                int index = std::stoi(data);
                std::cout << current_text.at(index-1) << std::endl;
                break;
            }

            case '4':  {
                history.pop();
                current_text = history.current_val();
                break;
            }
        }
    }
}

std::string caesarCipher(std::string s, int k) {

    std::string result = "";

    for (auto letter : s) {
        
        if (isalpha(letter)) {
            int asci_val = static_cast<int>(letter);
            if(asci_val >=97 && asci_val + k > 122) {                
                int letter_val = static_cast<int>('a') + (asci_val + k - 122) -1;
                result += static_cast<char>(letter_val);
            } else if (asci_val <= 90 && asci_val + k > 90)  {
                int letter_val = static_cast<int>('A') + (asci_val + k - 90) -1;
                result += static_cast<char>(letter_val);
            } else {
                letter +=k;
                result += letter;
            }

        } else {
            result += letter;
        }
    }
    return result;
}

int superDigit(std::string n, int k) {
    
    std::string base = n;
    while (k > 1) {
        n += base;
        k--;
    }
    
    long long  digit = std::stol(n);
    
    if (digit < 10) {
        return digit;
    } else {
        long long total = 0;
        for (auto val : n) {
            total += val - '0';
        }
        return superDigit(std::to_string(total), k);
    }
}

std::string gridChallenge(std::vector<std::string> grid) {
    
    for (auto &row : grid) {
        for (int i=0; i<row.size(); i++) {
            for (int j=i+1; j <row.size(); j++) {
                if(row[i] > row[j]) {
                    char temp = row[i];
                    row[i] = row[j];
                    row[j] = temp;
                }
            }
        }  
    }

    for (int c=0; c<grid.size(); c++ ) {
        for (int i=0; i < grid.size()-1; i++) {

            if (grid[i].at(c) > grid[i+1].at(c)) {  
                return "NO";
            }
        
        }
    }

    return "YES";
}

void minimumBribes(std::vector<int> q) {

    int bribes=0;
    int n=q.size();
    //int i=0;
    for(int i=0;i<n;i++){
        if(q[i]>(i+1+2)){
            std::cout << "Too chaotic" << std::endl;
            return;
        }
        //else if(q[i]==i+1){continue;}
        
        for (int j = std::max(0, q[i] - 2); j < i; j++)
            if (q[j] > q[i]) bribes++;
        
    }
    std::cout << bribes << std::endl;

}

int truckTour(std::vector<std::vector<int>> petrolpumps) {

    int fuel = 0;
    int distance = 1;
    int required_stations = petrolpumps.size();

    for (int station = 0; station < petrolpumps.size(); station++) {
        int tank = 0;
        int total_visited_stations = 0;

        if (petrolpumps[station][fuel] + tank - petrolpumps[station][distance] < 0) {
            continue;
        }

        tank += petrolpumps[station][fuel] - petrolpumps[station][distance];
        total_visited_stations++;

        int next_station = station;
        
        while (total_visited_stations < required_stations) {
            next_station++;

            if (next_station == petrolpumps.size()) {
                next_station = 0;
            }

            if (petrolpumps[next_station][fuel] + tank - petrolpumps[next_station][distance] < 0) {
                break;
            }

            tank += petrolpumps[next_station][fuel] - petrolpumps[next_station][distance];
            total_visited_stations++;
        }

        if (total_visited_stations == required_stations) {
            return station;
        }
    }
    return 0;
}

std::string isBalanced(std::string s) {

    // you can use a stack to make it work,
    // push the openning brackets, and pop when you get a closing one of the same type.
    int processed_items = 0;

    if (s.size() % 2 == 1) 
        return "NO";
  
    for (int i=0; i<s.size()-1; i++) {
        int jump = 0;
        char val_at_i = s.at(i);

        char target;
        switch (val_at_i) {
            case '(':
                    target = ')';
                break;
            case '{':
                    target = '}';
                break;
            case '[':
                    target = ']';
                break;
            default:
                continue;
        }

        for (int j=i+1; j < s.size(); j++) {
            char val_at_j = s.at(j);

            if (val_at_j == val_at_i) {
                jump++;
                continue;
            }

            if (target == s.at(j)) {
                if (jump > 0) {
                    jump --;
                    continue;
                } else {
                    if ((j - i - 1) % 2 == 1) {
                        return "NO";
                    }
                    processed_items += 2;
                    break;
                }
            }
 
        }
    }

    if (processed_items == s.size()) {
        return "YES";
    }
    return "NO";

}

int pairs(int k, std::vector<int> arr) {
    // a better approach would be to use a set to add unique items
    // then use the k to find the pairs and map the result to the set
    // if the result exists then increment the result

    int result = 0;

    for (int i=0; i < arr.size()-1; i++) {
        for (int j=i+1; j < arr.size(); j++) {

            int diff = arr[i] - arr[j];

            if (diff < 0) {
                diff *= -1;
            }

            if (diff == k) {
                result ++;
            }
        }
    }
    return result;
}

int cookies(int k, std::vector<int> A) {
    int result = 0;
    bool done = false;

    while (!done) {
        int cookie1 = 0; // lowest
        int cookie2 = 0; // second_lowest

        if (A.size() == 1 && A[cookie1] < k) {
            return -1;
        }

        for (int i=0; i<A.size(); i++) {
            if(A[i] > A[cookie2]) {
                cookie2 = i;
            }
        }

        for (int i=0; i<A.size(); i++) {
            if (A[i] < k && A[i] < A[cookie1]) {
                cookie1 = i;
            }
        }

        for (int i=0; i<A.size(); i++) {
             if (A[i] > A[cookie1] && A[i] < A[cookie2]) {
                cookie2 = i;
            }
        }

        if (A[cookie1] < k) {
            int new_cookie = A[cookie1] + A[cookie2] * 2;
            if (cookie1 > cookie2) {
                A.erase(A.begin() + cookie1);
                A.erase(A.begin() + cookie2);
            } else {
                A.erase(A.begin() + cookie2);
                A.erase(A.begin() + cookie1);
            }
            A.push_back(new_cookie);
            result ++;
        } else {
            break;
        }
    }

    return result;
}

void generateRows(std::vector<std::vector<int>>& rows, std::vector<int>& row, int row_size, int current_sum) {
    if (current_sum == row_size) {
            std::vector<int> entry = row;
            rows.push_back(entry);
        return;
    }

    for (int i = 1; i <= 4; ++i) {
        if (current_sum + i <= row_size) {
            row.push_back(i);
            generateRows(rows, row, row_size, current_sum + i);
            row.pop_back();
        }
    }
}

int legoBlocks(int h, int w) {

    int result = 0;
    std::vector<std::vector<int>> rows;
    std::vector<int> row;

    generateRows(rows, row, w ,0);

    if (h==0) {
        return rows.size();
    }

    for (int i=0; i<h-1; i++) {
        int first_row_index = i;
        int second_row_index = i+1;

        // for (auto top_row) {

        // }

    }
    
    


    return result;
}

int search_node(std::vector<std::vector<int>>& edges, int starting_node, int current_node, int target_node, int previous_node, bool& found) {

    int result = 0;

    std::vector<int> adjacent_nodes;
    for (auto edge : edges) {
        if (edge[0] == current_node || edge[1] == current_node) {
            if (edge[0] == target_node || edge[1] == target_node) {
                found = true;
                return 6;
            }
            if (edge[0] == current_node) { // record adjacent nodes
                adjacent_nodes.push_back(edge[1]);
            } else {
                adjacent_nodes.push_back(edge[0]);
            }
        }
    }

    for (auto node : adjacent_nodes) {
        if (node == starting_node || node == current_node || node == previous_node) {
            continue;
        }
        for (auto edge : edges) {
            if (edge[0] == node || edge[1] == node) {
                int distance = search_node(edges, starting_node, node, target_node, current_node, found);
                if (found) {
                    result += distance + 6;
                    break;
                }
            }
        }
    }

    if (found)
        return result;

    return -1;
}

std::vector<int> bfs(int n, int m, std::vector<std::vector<int>> edges, int s) {

    std::vector<int> result;

    for (int node=1; node <=n; node++) {
        if (node == s) {
            continue;
        }

        bool found = false;
        int distance = search_node(edges, s, s, node, s, found);

        result.push_back(distance);

    }

    return result;
}

std::string encryption(std::string s) {
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

    int length = s.size();
    int rows = std::sqrt(length);
    int columns = rows;


    while (rows * columns < length) {
        columns++;

        if (rows * columns < length)
            rows++;
    }

    std::vector<std::vector<char>> table;

    int string_indix = 0;
    for (int i=0; i<rows && string_indix<length; i++) {
        std::vector<char> row;
        for (int j=0; j<columns && string_indix < length; j++, string_indix++) {
        
            row.push_back(s.at(string_indix));
        }
        table.push_back(row);
    }

    std::string result;

    for (int column=0, count=0; column < columns && count < length; column++) {
        for (int row=0; row < rows && count < length; row++) {
            if (column < table[row].size()) {
                result += table[row][column];
                count++;
            }
        }
        if (count == length)
            break;
        
        result += " ";
    }

    return result;
}

std::vector<int> breakingRecords(std::vector<int> scores) {

    int best_score = 0;
    int worst_score = 0;

    int best_count = 0;
    int worst_count = 0;

    best_score = scores[0];
    worst_score = best_score;

    for (int i=1; i<scores.size(); i++) {
        if (scores[i] > best_score) {
            best_score = scores[i];
            best_count++;
        } else if (scores[i] < worst_score) {
            worst_score = scores[i];
            worst_count++;
        }
    }

    return std::vector<int> {best_count, worst_count};
}

int migratoryBirds(std::vector<int> arr) {

    std::vector<int> types {0, 0, 0, 0, 0};

    for (int i=0; i<arr.size(); i++) {
        types[arr[i]-1]++;
    }

    int max_val = 0;
    for (auto item: types)
        if (item > max_val)
            max_val = item;
    
    for (int i=0; i< types.size(); i++) {
        if (types[i] == max_val)
            return i+1;
    }
    return 0;
}

int getMinimumCost(int k, std::vector<int> c) {

    for (int i=0; i<c.size(); i++) {
        for (int j=i+1; j<c.size(); j++) {
            if (c[i] > c[j]) {
                int temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }

    int result = 0;
    std::vector<int> streak (k,1);

    int friend_index = 0;
    for (int i=c.size()-1; i>=0; i--) {
        
        result += streak[friend_index] * c[i];
        streak[friend_index]++;
        friend_index ++;

        if (friend_index >= streak.size())
            friend_index = 0;
    }

    return result;
}


