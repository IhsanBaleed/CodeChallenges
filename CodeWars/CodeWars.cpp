#include "CodeWars.hh"
#include <iostream>


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

