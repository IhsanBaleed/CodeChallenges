#include "Arrays.hh"
#include <set>
#include <vector>

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

int ReverseInt(int num) {

    std::vector<int> digits;
    int result = 0;

    while (num > 0) {
        int digit = num % 10;
        if (digit == 0 && digits.size() == 0) {
            num = num / 10;
        }
        else {
            digits.push_back(num % 10);
            num = num / 10;
        }
    }

    int multiplier = 1;
    for (auto digit : digits) {
        result *= multiplier;
        result += digit;
        if (multiplier < 10) {
            multiplier *= 10;
        }
    }
    return result;
}
