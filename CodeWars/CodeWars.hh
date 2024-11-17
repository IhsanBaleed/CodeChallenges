#include <vector>
#include <string>

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
