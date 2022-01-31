#include <vector>
#include <limits>
#include <iostream>

float maxValue(std::vector<float> numbers) {
    float max = -std::numeric_limits<float>::infinity();
  for (float num : numbers){
      if( num > max){
          max = num;
      }
  }
  std::cout << max << std::endl;
  return max;
}


int main() {

std::vector<float> numbers1{ 4, 7, 2, 8, 10, 9 };
maxValue(numbers1); // -> 10

std::vector<float> numbers2{ 10, 5, 40, 40.3 };
maxValue(numbers2); // -> 40.3

std::vector<float> numbers3{ -5, -2, -1, -11 };
maxValue(numbers3); // -> -1

std::vector<float> numbers4{ 42 };
maxValue(numbers4); // -> 42

std::vector<float> numbers5{ 1000, 8 };
maxValue(numbers5); // -> 1000

std::vector<float> numbers6{ 1000, 8, 9000 };
maxValue(numbers6); // -> 9000

std::vector<float> numbers7{ 2, 5, 1, 1, 4 };
maxValue(numbers7); // -> 5

}