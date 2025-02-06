#include "StringChallenges.hh"
#include <iostream>
#include <map>

// link: https://edabit.com/challenge/HipNbqHrErSYsM63T
// Medium - 17 mins 
// you can also use 		std::swap(s[i],s[i+1]);

std::string unmix(std::string str) {
	std::string result;
	for (int i = 0; i < str.length(); i+=2) {
		if (i < str.length()-1) {
			result += str[i+1];
			result += str[i];
		} else {
			result += str[i];
		}
	}
	return result;
}


// Link: https://edabit.com/challenge/ZA7D6GqyAgkzcnGad
// Medium - 9 Mins
// you can also use 	return str.find("zip", str.find("zip") + 3);

int findZip(std::string str) {
    bool found_first = false;
    int index = -1;
    for (int i=0; i < str.length()-2; i++) {

        if (str[i] == 'z' && str[i+1] == 'i' &&str[i+2] == 'p') {
                
            if(!found_first)
                found_first = true;
            else {
                return i;
            }
        }
    }
    return index;
}


// Link: https://edabit.com/challenge/n2Xdw3jdm6tpBLxS6
// Medium - 13 Mins
// Good solution, pay attention with loop counters.

std::string extendVowels(std::string word, int num) {
	std::string result;
    if (num < 0)
        return "Invalid";
    for (int i = 0; i < word.length(); i++) {
        char letter = tolower(word.at(i));
        result += word.at(i);
        if (letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'a' || letter == 'y'){
            for (int j =0; j < num; j++) {
                result += word.at(i);
            }
        }
    }
    return result;
}


// Link: https://edabit.com/challenge/mEEsMKznTCq25PWvD
// Hard - 10 Mins

std::string toCamelCase(std::string str) {

    std::string result;
    for (int i=0; i < str.length(); i++) {
        char letter = str.at(i);
        if (letter == '_') {
            i++;
            result += toupper(str.at(i));
        }
        else {
            result += letter;
        }
    }

    return result;
}


std::string toSnakeCase(std::string str) {
    std::string result; 
    for (int i=0; i < str.length(); i++) {
        char letter = str.at(i);
        if (isupper(letter)) {
            result += "_";
            result += tolower(letter);
        }
        else {
            result += letter;
        }
    }

    return result;
	
}


std::vector<int> move_zeroes(const std::vector<int>& input) {
    std::vector<int> new_vec(input.size());
    int counter = 0;
    
    for (int i=0, j=0; i < input.size(); i++) {
        if (input[i] == 0) {
            counter++;
            continue;
        }
        new_vec[j] = input[i];
        j++;
    }

    while (counter > 0) {
        new_vec[input.size()-counter] = 0;
        counter --;
    }
  return new_vec;
}


int ware_house_locations(int stores, int* locations, long d) {
    
    int result = 0; // always initialise your vars
    int min_location = locations[0];
    int max_location = locations[0];

    for (int i=0; i < stores; i++) { // when met with a range, try to think logically about ranges
        if (min_location > locations[i]) {
            min_location = locations[i];
        }
        if (max_location < locations[i]) {
            max_location = locations[i];
        }
    }

    for (int x = min_location; x <= max_location; x++) {
        int current_distance = 0;
        for (int i=0; i < stores; i++) {
            
            int distance = x - locations[i];
            if (distance < 0) {distance *= -1;}
            current_distance += (2 * distance);

            if (current_distance > d) {
                break;
            }

            if (i == stores -1) {
                result++;
            }
        }
    }

    return result;
}


bool empty_map(std::map<char, std::size_t>& map) {

    for (auto item : map) {
        if (item.second > 0) { return false; }
    }
    return true;
}

int rate_limit(int n, char* input, int min_gap) {

    int chars_recorded = 0;

    std::vector<char> result;
    int result_index = 0;

    while(chars_recorded < n) {
        for (int input_ptr=0; input_ptr < n; input_ptr++) {
            if (chars_recorded == n) {
                break;
            }
            if (input[input_ptr] == '#') {
                    if (input_ptr == n-1) {
                    result.push_back('-');
                    result_index++;
                    break;
                }
                continue;
            }

            bool safe_to_insert = true;
            int place_to_check = result_index - 1;
            for (int gaps=0; gaps < min_gap; gaps++) {

                if (place_to_check < 0)
                    break;

                if (input[input_ptr] == result[place_to_check]) {
                    safe_to_insert = false;
                    break;
                }
                place_to_check --;
            }

            if (safe_to_insert) {
                result.push_back(input[input_ptr]);
                result_index++;
                chars_recorded++;
                input[input_ptr] = '#';
                continue;
            }
        }
    }

    return result.size();
}


