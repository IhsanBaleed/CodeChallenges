#include "Codility.hh" 
#include <iostream>
#include <algorithm>
#include <bitset>
#include <set>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <stack>
#include <map>


void print_vector(std::vector<int> &A) {
    for (auto& item : A)
        std::cout << item << ", " << std::endl; 
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

std::vector<int> GenomicRangeQuery(std::string& S, std::vector<int>& P, std::vector<int>& Q) {

    std::vector<int> res;

    // make the prefix sum arrays, make each one unique to its data type
    std::vector<int> a_data(S.size() + 1, 0);
    std::vector<int> c_data(S.size() + 1, 0);
    std::vector<int> g_data(S.size() + 1, 0);
    std::vector<int> t_data(S.size() + 1, 0);

    for (int i = 0; i < S.size(); i++) {

        a_data[i + 1] = a_data[i]; // let the arrays retain records of what came before
        c_data[i + 1] = c_data[i];
        g_data[i + 1] = g_data[i];
        t_data[i + 1] = t_data[i];

        if (S[i] == 'A') { // record the data into its respective array
            a_data[i + 1]++;
        }
        else if (S[i] == 'C') {
            c_data[i + 1]++;
        }
        else if (S[i] == 'G') {
            g_data[i + 1]++;
        }
        else if (S[i] == 'T') {
            t_data[i + 1]++;
        }
    }

    for (int i = 0; i < P.size(); i++) {

        int start = P[i];
        int end = Q[i];

        if (a_data[end + 1] - a_data[start] > 0) { // we have an A
            res.push_back(1);
        }
        else if (c_data[end + 1] - c_data[start] > 0) { // we have a B
            res.push_back(2);
        }
        else if (g_data[end + 1] - g_data[start] > 0) { // we have a C
            res.push_back(3);
        }
        else if (t_data[end + 1] - t_data[start] > 0) { // we have a D
            res.push_back(4);
        }
    }

    return res;
}

int CountDiv(int A, int B, int K) {

    int res = 0;

    int remainder = A % K;

    int first_factor = A;

    if (remainder != 0)
        first_factor = K + (A - remainder);
    if (first_factor > B)
        return 0;

    res = (B - first_factor) / K;
    res++;

    return res;
}

int MinAvgTwoSlice(std::vector<int>& A) {

    // pay attention to the problem's statement
    // to have a good solution, you must have a correct and thurough understanding of the issue.

    int index = 0;
    int lowest_sum = std::numeric_limits<int>::max();

    for (int i = 0; i < A.size() - 1; i++) {

        double slice_sum = (A[i] + A[i + 1]) / 2.0; // add .0 to make the devision fully for doubles

        if (slice_sum < lowest_sum) {
            lowest_sum = slice_sum;
            index = i;
        }

        if (i < A.size() - 2) {
            slice_sum = (A[i] + A[i + 1] + A[i + 2]) / 3.0;
            if (slice_sum < lowest_sum) {
                lowest_sum = slice_sum;
                index = i;
            }
        }
    }

    return index;
}

int NumberOfDistincsIntersections(std::vector<int>& A){

    // The solution for this requires a little bit of observation
    // look at the graph, it shows a better representation of the problem

    using namespace std;

    int N = A.size();
    if (N < 2) return 0; // No possible intersections

    vector<long> left(N), right(N);

    for (int i = 0; i < N; i++) {
        left[i] = (long)i - A[i];  // starting of a circle
        right[i] = (long)i + A[i]; // end of a circle
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int intersections = 0;
    int j = 0; // Pointer for left array
    int active_discs = 0;

    // Sweep line algorithm
    // You simply line up the opening archs of each disc, and you start accumelating them
    // Every time an arch closes, we close a disc
    // It is very similar to the passing Cars problem
    for (int i = 0; i < N; i++) {
        while (j < N && left[j] <= right[i]) { // as long as we have an opening, keep increasing the discs
            intersections += active_discs;
            active_discs++;
            j++;
            if (intersections > 10'000'000) return -1;
        }
        active_discs--; // Close current disc
    }

    return intersections;
}

int StoneWall(std::vector<int> &H) {

    int res = 0;
    std::stack<int> stones;

    for (auto& h : H) {

        if (stones.empty()) {
            stones.push(h);
            res++;
        } 
        else if (stones.top() < h) {
            stones.push(h);
            res++;
        } 
        else if (stones.top() > h) {

            while (!stones.empty() && stones.top() > h)
                stones.pop();
            
            if (!stones.empty()) {
                if (stones.top() < h) {
                    stones.push(h);
                    res++;
                }
            }
            else {
                stones.push(h);
                res++;
            }
        }
    }
    return res;
}

int Dominator(std::vector<int>& A) {

    if (A.size() == 1)
        return 0;

    std::map<int, int> matrix;
    int threshhold = (A.size() / 2) + 1;

    for (int i = 0; i<A.size(); i++) {
        if (matrix.find(A[i]) == matrix.end())
            matrix[A[i]]++;
        else {
            matrix[A[i]]++;
            if (matrix[A[i]] >= threshhold) {
                return i;
            }
        }
    }

    return -1;
}

int MaxProft(std::vector<int>& A) {

    if (A.size() < 2) {
        return 0; // No profit can be made with less than 2 elements
    }

    long result = 0;
    long seg_profit = 0;
    long zero = 0;

    for (long i = 0; i<A.size()-1; i++) {

        long profit = A[i + 1] - A[i];

        seg_profit = std::max(zero, seg_profit + profit);
        result = std::max(result, seg_profit);
    }

    return result;
}

int MaxSliceSum(std::vector<int>& A) {

    if (A.size() == 1)
        return A[0];
    
    std::vector<int> prefix_sum(A.size()+1, 0);

    int max_val = 0;
    for (int i = 0; i < A.size(); i++) {

        int slice = prefix_sum[i] + A[i];

        prefix_sum[i + 1] = std::max(0, slice);

        max_val = std::max(max_val, prefix_sum[i + 1]);
    }

    if (max_val > 0)
        return max_val;
    else {
        std::sort(A.begin(), A.end());
        return A[A.size() - 1];
    }
}

int MaxDoubleSliceSum(std::vector<int>& A) {

    int N = A.size();
    if (N < 3) return 0;

    std::vector<int> max_ending_here(N, 0);
    std::vector<int> max_starting_here(N, 0);

    for (int i = 1; i < N - 1; ++i) {
        max_ending_here[i] = std::max(0, max_ending_here[i - 1] + A[i]);
    }

    for (int i = N - 2; i > 0; --i) {
        max_starting_here[i] = std::max(0, max_starting_here[i + 1] + A[i]);
    }

    // the two slices must be adjacent, thus we take the two maximum slices we can get.
    // This is a key information you did not see, it would have solved the issue.
    // it also links to the creation of the two arrays at the top.
    int max_double_slice_sum = 0;
    for (int Y = 1; Y < N - 1; ++Y) {
        max_double_slice_sum = std::max(max_double_slice_sum, max_ending_here[Y - 1] + max_starting_here[Y + 1]);
    }

    return max_double_slice_sum;
}

