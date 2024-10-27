#include "StringChallenges.hh"



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

