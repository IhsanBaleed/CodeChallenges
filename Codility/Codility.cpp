#include "Codility.hh" 
#include <iostream>
#include <algorithm>
#include <bitset>
#include <set>
#include <stack>
#include <unordered_map>
#include <cmath>

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

std::string FormatString(std::string s) {
    std::string result;
    
    std::string triplet;
    for (int i=0; i< s.size(); i++) {
        if (std::isalnum(s.at(i))) {
            triplet += s.at(i);
        }
        
        if (triplet.size() == 3) {
            result += triplet + " ";
            triplet.clear();
        }
        if (i == s.size()-1) {
            if (triplet.size() == 2) {
                result += triplet + " ";
            } else if (triplet.size() == 1) {
                result.erase(result.size()-1);
                triplet = result.at(result.size()-1) + triplet;
                result.erase(result.size()-1);
                result += " " + triplet + " ";
            }
            
        }
    }
    
    result.erase(result.size()-1);
    result += ";";
    return result;
}

std::vector<int> CountNonDivisible(std::vector<int>& input) {

    // a better approach would be to
    // count the num of divisors for each number, upto the Num^2
    // see if they occure in the array, and count them
    // the rest would be non divisors

    std::vector<int> result(input.size(), 0);

    for (int i=0; i<input.size(); i++) {
        for (int j=i+1; j<input.size(); j++) {
            int x = input[i];
            int y = input[j];
            if (x == y)
                continue;
            if (x % y != 0)
                result[i]++;
            if (y % x != 0)
                result[j]++;
        }
    }

    return result;
}

void removeMinusOnes(std::vector<int>& vec) {
    vec.erase(std::remove(vec.begin(), vec.end(), -1), vec.end());
}

std::vector<int> CountSemiPrimes(int N, std::vector<int>& P,std::vector<int>& Q) {

    // you can also use vectors to store primes
    // and another one to store semis based on primes
    // use a third vector to make a note of how many semis are at each index
    // subtract based on the limit to see which how many semis between two limits

    std::vector<int> result(P.size());

    if (N == 1)
        return result;

    std::vector<int> primes(N-1);

    for (int i=0; i<N; i++)
        primes[i] = i+2;

    for (int i=0; (i*i) < N; i++) {     // generate primes    
        
        int prime = primes[i];

        if (prime == -1)
            continue;

        int k = prime * prime;

        for (;k <= N; k += prime) {
            primes[k-2] = -1;
        }
    }

    removeMinusOnes(primes);

    for (int i=0; i<P.size(); i++) {
        int lower = P[i];
        int upper = Q[i];

        int prime_index = 0;
        int prime = primes[prime_index];

        while (prime * prime < lower) { // find lowest possible prime
            prime_index++;
            prime = primes[prime_index];
        }

        std::set<int> semis;

        for (; (prime*2) <= upper; prime_index++, prime = primes[prime_index]) {
            for (auto& val : primes) {

                int semi = prime * val;

                if (semi >= lower && semi <= upper) {
                    semis.insert(semi);
                    continue;
                }

                if (semi > upper)
                    break;

            }
        }
        result[i] = semis.size();
    }

    return result;
}

int Fish(std::vector<int> A, std::vector<int> B) {

    int result = A.size();

    std::stack<std::pair<int, int>> fish;

    for (int i=0; i<A.size(); i++) {

        if (fish.empty()) {
            fish.push(std::pair(A[i],B[i]));
            continue;
        }

        std::pair<int,int> f1 = fish.top();
        std::pair<int,int> f2 (A[i], B[i]);

        if (f1.second == 1 && f2.second == 0) {

            if (f1.first > f2.first) {
                result--;
                continue;
            } else {
                fish.pop();
                result--;

                while (!fish.empty() && fish.top().second == 1) {
                    if (fish.top().first > f2.first) {
                        result --;
                        break;
                    } else {
                        fish.pop();
                        result --;
                    }
                }

                if (fish.empty() || fish.top().second == 0) {
                    fish.push(f2);
                    continue;
                }
            }
        } else {
            fish.push(f2);
        }
    }

    return result;
}

int highest_num(std::unordered_map<int,int> map, int& amount) {
    int num = 0;
    int highest_occurance = 0;

    for (auto& pair : map) {
        if (pair.second > highest_occurance) {
            highest_occurance = pair.second;
            num = pair.first;
        }
    }

    amount = highest_occurance;
    return num;
}

int EquiLeader(std::vector<int>& A) {

    if (A.size() == 1)
        return 0;
    
    int result = 0;

    std::unordered_map<int, int> lhs;
    std::unordered_map<int, int> rhs;

    for (int i=0; i<A.size(); i++)
        rhs[A[i]]++;

    for (int i=0; i<A.size()-1; i++) {
        lhs[A[i]]++;
        rhs[A[i]]--;

        int lhs_occur = 0;
        int lhs_leader = highest_num(lhs, lhs_occur);

        if (lhs_occur > (i+1)/2) {

            int rhs_occur = 0;
            int rhs_leader = highest_num(rhs, rhs_occur);

            if (rhs_leader != lhs_leader)
                continue;
            if (rhs_occur <= (A.size()-1-i)/2)
                continue;
            
            result++;
        }
    }

    return result;
}

int CountFacotrs(int n) {

    std::set<int> factors;

    factors.emplace(n);
    factors.emplace(1);

    int root = std::sqrt(n);

    for (int i=2; i<= root; i++) {

        if (factors.find(i) != factors.end())
            continue;

        int factor = i;

        while (n % factor == 0 && factor <= root) {
            factors.emplace(factor);
            factors.emplace(n/factor);
            factor += i;
        }

    }

    return factors.size();
}

int PassingCars(std::vector<int>& Cars) {

    long long result = 0;

    int going_east = 0;

    for (auto& car : Cars) {
        if (car == 0)
            going_east++;
        else {
            result += going_east;
        }
    }

    if (result > 1000000000)
        return -1;

    return result;
}
