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


bool empty_map(std::map<char, uint>& map) {

    for (auto item : map) {
        if (item.second > 0) { return false; }
    }
    return true;
}

int rate_limit(int n, char* requests, int min_gap) {

    if (min_gap == 0) {
        return n;
    }

    std::map<char, uint> total_requests;

    for (int i=0; i<n; i++) {
        if (total_requests.find(requests[i]) == total_requests.end()) {
            total_requests.insert(std::make_pair(requests[i], 1));
            continue;
        } 
        total_requests[requests[i]]++;
    }

    std::vector<char> new_data;

    for (auto it = total_requests.begin(); it != total_requests.end(); ++it) {
        int buffer = min_gap;

        for (int i=0; i < it->second;) {
            new_data.push_back(it->first);
            it->second -=1;

            auto next_it = it;
            next_it++;

            for (int j=0; j < min_gap && !empty_map(total_requests); j++) {
                if (next_it == total_requests.end()) { // End of buffer chars
                    new_data.push_back('-');
                } else {
                    new_data.push_back(next_it->first);
                    next_it->second -= 1;
                    char current_char = next_it->first;
                    
                    if(next_it->second == 0) {
                        next_it++;
                        total_requests.erase(current_char);
                    } else {next_it++;}
                }
            }
        }
    }

    return new_data.size();
}


