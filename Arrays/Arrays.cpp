#include "Arrays.hh"
#include <set>

std::vector<int> SkyScrapper(std::vector<int> A_data) {

    std::vector<int> result;

    for (int i=0; i <A_data.size(); i++) {
        bool found = false;

        for (auto& result_entry : result) {

            if (A_data[i] == result_entry) {
                A_data[i] -= 1;
                found = true;
            }
        }
        if (found) {
            i --;
        } else {
            result.push_back(A_data[i]);
        }
    }

    return result;
}

int RemoveLetters(std::string S) {
    std::set<char> distinctChars;

    for (char c : S) {
        distinctChars.insert(c);
    }

    int odd_chars = 0;
    
    for (auto c_set : distinctChars) {
        int chars_in_string = 0;
        for (char c_sourse : S) {
            if (c_set == c_sourse) {
                chars_in_string++;
            }
        }
        odd_chars += (chars_in_string % 2);
    }

    if (odd_chars > 1) {
        return odd_chars -1;
    }
    return 0;
}
