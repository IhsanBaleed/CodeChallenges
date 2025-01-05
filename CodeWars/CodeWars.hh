#include <vector>
#include <list>
#include <string>
#include <map>

int multiple_3_5(int val);

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map);

typedef unsigned long long ull;
class ProdFib
{
public:
  
  static ull fibonacci(ull val) {
    if (val == 0) {
      return 0;
    }
    if (val == 1) {
      return 1;
    }
    return fibonacci(val-1) + fibonacci(val-2);
  }
  
  static std::vector<ull> productFib(ull prod) {
    
    std::vector<ull> result;
    
    ull first_element  = 0;
    ull second_element = 0;
    
    ull max_val = 0;
    int index=1; 
    while (max_val < prod) {
      first_element = fibonacci(index);
      second_element = fibonacci(index - 1);
      max_val = first_element * second_element;
      index++;
    }

    result.push_back(second_element);
    result.push_back(first_element);
    
    if (max_val > prod) {
      result.push_back(false);
    } else {
      result.push_back(true);
    }

    return result;
  }
};

std::string format_duration(int seconds);

bool validate_battlefield(std::vector<std::vector<int>> field);

std::string encode_rail_fence_cipher(const std::string &str, int n);

std::string decode_rail_fence_cipher(const std::string &str, int n);

int last_digit(const std::string &str1, const std::string &str2);

int last_digit(std::list<int> lst);

std::string range_extraction(std::vector<int> args);

std::vector<std::string> get_pins(std::string observed);

class RomanHelper{

  std::map<int, std::string> numerals {
    {1, "I"},
    {2, "II"},
    {3, "III"},
    {4, "IV"},
    {5, "V"},
    {6, "VI"},
    {7, "VII"},
    {8, "VIII"},
    {9, "IX"},
    {10, "X"},
    {50, "L"},
    {100, "C"},
    {500, "D"},
    {1000, "M"}
  };

public:

  std::string to_roman(unsigned int n) {

    std::string result;
    
    int factor = n % 10;

    if (factor > 0)
      result = numerals[factor];
    
    factor = (n%100) / 10;
    if (factor > 0) {
      if (factor < 4) { // 10-30
        for (int i=0; i<factor; i++){
          result = numerals[10] + result;
        }
      } else if (factor == 4) { // 40
        result = numerals[10] + numerals[50] + result;
      } else if (factor < 9) { // 50 - 80
          std::string tmp = numerals[50];
          factor -= 5;
          for (int i=0; i<factor; i++)
            tmp = tmp + numerals[10];
          result = tmp + result;
      } else { // 90
        result = numerals[10] + numerals[100] + result;
      }
    }

    factor = (n%1000) / 100;
    if (factor > 0) {
      if (factor < 4) {
        for (int i=0; i<factor; i++){
          result = numerals[100] + result;
        }
      } else if (factor == 4) {
        result = numerals[100] + numerals[500] + result;
      } else if (factor < 9) {
          std::string tmp = numerals[500];
          factor -= 5;
          for (int i=0; i<factor; i++)
            tmp = tmp + numerals[100];
          result = tmp + result;
      } else {
        result = numerals[100] + numerals[1000] + result;
      }
    }

    factor = n / 1000;
    for (int i=0; i<factor; i++)
      result = numerals[1000] + result;

      return result;
  }

  int from_roman(std::string rn) {

    int result = 0;

    for (int i=0; i<rn.size(); i++) {
    
      std::string letter(1, rn[i]);

      if (letter == "M")
        result += 1000;

      if (letter == "D")
        result += 500;

      if (letter == "C") { // CM = 900
        if (i+1 < rn.size() && rn[i+1] == 'M') {
          result += 900;
          i++;
        } else if (i+1 < rn.size() && rn[i+1] == 'D') { // CD = 500
          result += 400;
          i++;
        } else
          result += 100;
      }

      if (letter == "L")
        result += 50;

      if (letter == "X") {
        if (i+1 < rn.size() && rn[i+1] == 'C') { // XC = 90
          result += 90;
          i++;
        } else if (i+1 <rn.size() && rn[i+1] == 'L') { // XL = 40
          result += 40;
          i++;
        } else 
          result += 10;
      }

      if (letter == "V")
        result += 5;

      if (letter == "I") {
          if (i+1 < rn.size() && rn[i+1] == 'X') { // IX = 9
            result += 9;
            i++;
        } else if (i+1 <rn.size() && rn[i+1] == 'V') { // IV = 4 
          result += 4;
          i++;
        } else 
          result ++;
      }
    }

    return result;
  }
};

int FirstFactorial(int num) ;

std::string FindIntersection(std::string strArr[], int arrLength);

