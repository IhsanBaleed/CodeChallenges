#include "Codility.hh" 
#include <iostream>
#include <algorithm>
#include <bitset>
#include <set>

void print_vector(std::vector<int> &A) {
    for (auto& item : A)
        std::cout << item << ", " << std::endl; 
}

int MaxDoubleSliceSum(std::vector<int> &A) {
    int N = A.size();
    std::vector<int> max_ending_here(N, 0);
    std::vector<int> max_starting_here(N, 0);

    for (int i = 1; i < N - 1; ++i) {
        max_ending_here[i] = std::max(0, max_ending_here[i - 1] + A[i]);
    }

    for (int i = N - 2; i > 0; --i) {
        max_starting_here[i] = std::max(0, max_starting_here[i + 1] + A[i]);
    }

    int max_double_slice_sum = 0;
    for (int Y = 1; Y < N - 1; ++Y) {
        max_double_slice_sum = std::max(max_double_slice_sum, max_ending_here[Y - 1] + max_starting_here[Y + 1]);
    }

    return max_double_slice_sum;
}

int OddOccurenceaInArray(std::vector<int> &A) {
    
    std::sort(A.begin(), A.end());

    print_vector(A);

    for (int i=0; i<A.size(); i++) {

        if (i == A.size()-1)
            return A[i];
        
        if (A[i] != A[i+1])
            return A[i];
        else 
            i++;
    }

    return 0;
} 

int BinaryGap(int N) {

    std::string data = std::bitset<32>(N).to_string();

    int max_gap = 0;
    
    int gap = 0;
    bool in_gap = false;
    
    for (int i=0; i<data.size(); i++) {
        
        if (i > 0) {

            if (data.at(i) == '0' && data.at(i-1) == '1') {
                in_gap = true;
            }

            if (in_gap) {
                if(data.at(i) == '0') {
                    gap++;
                } else {
                    in_gap = false;
                    if (gap > max_gap)
                        max_gap = gap;

                    gap = 0;
                }
            }

        }
    }

    return max_gap;
}

int PermMissingElem(std::vector<int> &A) {

    std::sort(A.begin(), A.end());

    if (A.size() > 0 &&  A[0] != 1)
        return 1;

    for (int i=0; i < A.size()-1 && !A.empty(); i++) {
        if (A[i+1] - A[i] > 1)
            return A[i]+1;
    }

    return A.size() + 1;
}

int ChocByNumbers(int N, int M) {

    int result = 0;
    
    if (N > 0) {

        int X = (0+M) % N;

        std::set<int> wrappers;
        wrappers.insert(0);
        result++;

        while (true) {

            if (wrappers.find(X) != wrappers.end()) { // found
                break;
            }

            result++;
            wrappers.insert(X);

            X = (X+M) % N;
        }

    }

    return result;
}

int Dominator(std::vector<int> &A) {

    int count = 0;
    int item = 0;
    int index = -1;

    bool found = false;

    if (A.size() > 0) {

        std::vector<int> sorted_array(A);

        std::sort(sorted_array.begin(), sorted_array.end());

        item = sorted_array[0];
        count ++;

        for (int i=1; i<sorted_array.size(); i++) {

            if (item == sorted_array[i]) {
                count ++;
            } else {
                item = sorted_array[i];
                count = 1;
            }

            if (count > A.size()/2) {
                found = true;
                break;
            }

            if (i > A.size()/2 && count < A.size()/2)
                break;
        }

    }

    if (found) {
        for (int i=0; i<A.size(); i++) {
            if (item == A[i]) {
                index = i;
                break;
            }
        }
    }

    return index;
}


