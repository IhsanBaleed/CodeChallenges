#include "CodeWars.hh"
#include <iostream>
#include <cmath>


int multiple_3_5(int val) {
    if (val < 0) {
        return 0;
    }

    int result = 0;

    for (int i=1; i < val; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            result += i;
        }
    }
    
    return result;
}

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {    

    std::vector<int> result;

    if (snail_map.size() == 1 && snail_map[0].size()== 0) {
        return result;
    }

    bool working = true;
    
    int lhs_index = 0;
    int rhs_index = snail_map.size() - 1;

    int top_row_index = 0;
    int bottom_row_index = snail_map.size()-1;

    while (working) {
                
        for (int i=lhs_index; i<=rhs_index; i++) {
            result.push_back(snail_map[top_row_index][i]);
        }
        top_row_index++;

        for (int j=top_row_index; j<= bottom_row_index; j++) {
           result.push_back(snail_map[j][rhs_index]);
        }
        rhs_index --;

        for (int x=rhs_index; x>= lhs_index; x--) {
            result.push_back(snail_map[bottom_row_index][x]);
        }
        bottom_row_index --;

        for (int y=bottom_row_index; y>=top_row_index; y--) {
            result.push_back(snail_map[y][lhs_index]);
        }
        lhs_index++;

        if (top_row_index > bottom_row_index) {
            break;
        }
    }

    return result;
}

std::string format_duration(int seconds) {

    std::string result;

    if (seconds == 0) {
        return "now";
    }

    int secs = 0;
    int mins = 0;
    int hours = 0;
    int days = 0;
    int years = 0;

    if (seconds / (3600 * 24 * 365) >= 1) {
        years = seconds / (3600 * 24 * 365);
        seconds -= years * (3600 * 24 * 365);

        if (seconds == 0) {
            if (years > 1)
                result += std::to_string(years) + " years";
            else 
                result += std::to_string(years) + " year";
        } else {
            if (years > 1)
                result += std::to_string(years) + " years";
            else 
                result += std::to_string(years) + " year";
        }
    }

    if (seconds / (3600 * 24) >= 1) {
        days = seconds / (3600 * 24);
        seconds -= days * (3600 * 24);

        if (seconds == 0) {
            if (!result.empty())
                result += " and ";
            if (days > 1)
                result += std::to_string(days) + " days";
            else 
                result += std::to_string(days) + " day";
        } else {
            if (!result.empty())
                result += ", ";
            if (days > 1)
                result += std::to_string(days) + " days";
            else 
                result += std::to_string(days) + " day";
        }
    }

    if (seconds / (3600) >= 1) {
        hours = seconds / (3600);
        seconds -= hours * (3600);

        if (seconds == 0) {
            if (!result.empty())
                result += " and ";
            if (hours > 1)
                result += std::to_string(hours) + " hours";
            else 
                result += std::to_string(hours) + " hour";
        } else {
            if (!result.empty())
                result += ", ";
            if (hours > 1)
                result += std::to_string(hours) + " hours";
            else 
                result += std::to_string(hours) + " hour";
        }
    }

    if (seconds / (60) >= 1) {
        mins = seconds / (60);
        seconds -= mins * (60);

        if (seconds == 0) {
            if (!result.empty())
                result += " and ";
            if (mins > 1)
                result += std::to_string(mins) + " minutes";
            else 
                result += std::to_string(mins) + " minute";
        } else {
            if (!result.empty())
                result += ", ";
            if (mins > 1)
                result += std::to_string(mins) + " minutes";
            else 
                result += std::to_string(mins) + " minute";
        }
    }

    secs = seconds;
    if (secs > 0) {
         if (!result.empty())
                result += " and ";
        if (secs > 1)
            result += std::to_string(seconds) + " seconds";
        else
            result += std::to_string(seconds) + " second";
    }

    return result;
}

bool validate_battlefield(std::vector<std::vector<int>> field) {

    int battle_ship = 0;
    int crusiers = 0;
    int destoryers = 0;
    int subs = 0;

    int grid_size = field.size();

    for (int row=0; row < grid_size; row++) {
        for (int column=0; column < grid_size; column++) {

            int full_cells = 0;

            if(field[row][column] == 1) {
                full_cells++;
                field[row][column] = 2;

                if (row-1 >= 0 && column-1 >= 0 &&               field[row-1][column-1] > 0)
                    return false;
                if (row-1 >= 0 && column+1 < grid_size &&        field[row-1][column+1] > 0)
                    return false;
                if (row+1 < grid_size && column-1 >= 0 &&        field[row+1][column-1] > 0)
                    return false;
                if (row+1 < grid_size && column+1 < grid_size && field[row+1][column+1] > 0)
                    return false;

                for (int i=column+1; i<grid_size; i++) { // check right
                    if(field[row][i] == 1) {
                        full_cells++;
                        field[row][i] = 2;

                        if (row-1 >= 0 && i-1 >= 0 &&               field[row-1][i-1] > 0)
                            return false;
                        if (row-1 >= 0 && i+1 < grid_size &&        field[row-1][i+1] > 0)
                            return false;
                        if (row+1 < grid_size && i-1 >= 0 &&        field[row+1][i-1] > 0)
                            return false;
                        if (row+1 < grid_size && i+1 < grid_size && field[row+1][i+1] > 0)
                            return false;
                    }
                    else 
                        break;
                }

                for (int j=row+1; j<grid_size; j++) { // check down
                    if(field[j][column] == 1) {
                        full_cells++;
                        field[j][column] = 2;

                        if (column-1 >= 0 && j-1 >= 0 &&                field[j-1][column-1] > 0)
                            return false;
                        if (column+1 < grid_size && j-1 >= 0 &&         field[j-1][column+1] > 0)
                            return false;
                        if (column-1 >=0 && j+1 < grid_size &&          field[j+1][column-1] > 0)
                            return false;
                        if (j+1 < grid_size && column+1 < grid_size &&  field[j+1][column+1] > 0)
                            return false;
                    }
                    else 
                        break;
                }

                switch (full_cells) {
                    case 4:
                        battle_ship++;
                        break;
                    case 3:
                        crusiers++;
                        break;
                    case 2:
                        destoryers++;
                        break;
                    case 1:
                        subs++;
                        break;
                    case 0:
                        break;
                    
                    default:
                        return false;
                        break;
                    }
            }
        }
    }
    if (battle_ship == 1 && crusiers == 2 && destoryers == 3 && subs == 4)
        return true;
    return false;
}

std::string encode_rail_fence_cipher(const std::string &str, int n) {
  if (str.empty())
    return "";

    std::string result;
    std::vector<std::vector<char>> rails;

    for (int i=0; i<n; i++) {
        std::vector<char> rail;
        rails.push_back(rail);
    }

    int rail_pos = 0;
    bool zig = true;
    for (auto letter : str) {

        if (rail_pos == n) {
            zig = false;
            rail_pos -= 2;
        }
        if (rail_pos == 0) {
                zig = true;
        }
        if (zig) {
            rails[rail_pos].push_back(letter);
            rail_pos ++;
        } 
        if (!zig) {
            rails[rail_pos].push_back(letter);
            rail_pos --;
        }
    }

    for (auto rail : rails) {
        for (auto letter : rail) {
            result += letter;
        }
    }

    return result;
}

std::string decode_rail_fence_cipher(const std::string &str, int n) {
    if (str.empty())
        return "";

    std::string result;
    std::vector<std::vector<char>> rails;

    for (int i=0; i<n; i++) {
        std::vector<char> rail;
        rails.push_back(rail);
    }

    int rail_pos = 0;
    bool zig = true;
    for (auto letter : str) {

        if (rail_pos == n) {
            zig = false;
            rail_pos -= 2;
        }
        if (rail_pos == 0) {
                zig = true;
        }
        if (zig) {
            rails[rail_pos].push_back('#');
            rail_pos ++;
        } 
        if (!zig) {
            rails[rail_pos].push_back('#');
            rail_pos --;
        }
    }

    int starting_point = 0;
    std::vector<int> points;
    points.push_back(starting_point);
    for(int i=0; i<rails.size()-1; i++) {
        starting_point += rails[i].size();
        points.push_back(starting_point);
    }

    bool zag = true;
    rail_pos = 0;
    while (result.size() < str.size()) {
        
        if(rail_pos == n) {
            zag = false;
            rail_pos -= 2;
        }
        if (rail_pos == 0) {
            zag = true;
        }
        if (zag) {
            if (points[rail_pos] < str.size()) {
                result += str.at(points[rail_pos]);
                points[rail_pos]++;            
            }
            rail_pos ++;
        } 
        if (!zag) {
            if (points[rail_pos] < str.size()) {
                    result += str.at(points[rail_pos]);      
                    points[rail_pos]++;
            }
            rail_pos --;
        }
    }

    return result;
}

int last_digit(const std::string &str1, const std::string &str2) {

    if (str2 == "0") {
        return 1;
    }
  
    int base_num = str1.at(str1.size()-1) - '0';

    int power = 0;
    if (str2.size() > 1) {
        power = std::stoi(str2.substr(str2.size()-2,2)) % 4;
    } else {
        power = std::stoi(str2.substr(str2.size()-1,1)) % 4;
    }

    if (power == 0) {
        power += 4;
    }

    int result =  std::pow(base_num, power);

    result %= 10;

return result;
}

std::string range_extraction(std::vector<int> args) {

    std::string result;

    if (args.size() <= 2) {
        for (auto& item: args) {
            result += std::to_string(item);
            result += ",";
        }
        return result;
    }

    for (int i=0; i<args.size();) {
        int elements = 0;

        if (i == args.size()-1) {
            result += std::to_string(args[i]);
            break;
        }

        if (args[i] - args[i+1] == -1) {
            elements+= 2;

            for (int j=i+1; j<args.size()-1; j++) {
                if (args[j] - args[j+1] == -1) {
                    elements++;
                } else {
                    break;
                }
            }

            if (elements >= 3) {
                result += std::to_string(args[i]);
                result += "-";
                result += std::to_string(args[i+elements-1]);
                i += elements;
                if (i < args.size())
                    result += ",";
                continue;
            } else {
                result += std::to_string(args[i]);
                result += ",";
                i++;
            }
        } else {
            result += std::to_string(args[i]);
            result += ",";
            i++;
        }
    }

    return result;
}

std::map<std::string, std::vector<std::string>> digits_map {
    {"0", {"0","8"}},
    {"1", {"1", "2", "4"}},
    {"2", {"2", "1", "3", "5"}},
    {"3", {"3", "2", "6"}},
    {"4", {"4", "1", "5", "7"}},
    {"5", {"5", "2", "4", "6", "8"}},
    {"6", {"6", "3", "5", "9"}},
    {"7", {"7", "4", "8"}},
    {"8", {"8", "5", "7", "9", "0"}},
    {"9", {"9", "6", "8"}}
};

void generatePermutations(const std::string& input, std::string current, int index, std::vector<std::string>& result) {
    if (index == input.size()) {
        result.push_back(current);
        return;
    }

    std::string digit = std::string(1, input[index]);
    if (digits_map.find(digit) != digits_map.end()) {
        for (const auto& replacement : digits_map[digit]) {
            generatePermutations(input, current + replacement, index + 1, result);
        }
    } else {
        generatePermutations(input, current + digit, index + 1, result);
    }
}

std::vector<std::string> getAllPermutations(const std::string& input) {
    std::vector<std::string> result;
    generatePermutations(input, "", 0, result);
    return result;
}

std::vector<std::string> get_pins(std::string observed) {

    std::vector<std::string> result = getAllPermutations(observed);

    return result;
}
