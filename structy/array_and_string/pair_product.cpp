#include <array>
#include <vector>
#include <iostream>
#include <unordered_map>

//Write a function, pairProduct, that takes in a vector of numbers and a target product as arguments. The function should
//return a std::array containing a pair of indices whose elements multiply to the given target. The indices returned must
//be unique.

//Be sure to return the indices, not the elements themselves.

//There is guaranteed to be one such pair whose product is the target.

std::array<int, 2> pairProduct(std::vector<int> numbers, int target) {
    std::unordered_map<int, int> hashMap;
    for(int i = 0; i < numbers.size(); i+=1){
        int current = numbers[i];
        int complement = target / current;

        if(hashMap.count(complement) > 0){
            std::cout << hashMap[complement] << " , " << i << std::endl;
            return std::array<int, 2> { hashMap[complement], i };
        }

        hashMap[current] = i;
    }
}

int main () {
    std::vector<int> numbers { 3, 2, 5, 4, 1 };  
    pairProduct(numbers, 8); // -> [1, 3]

    std::vector<int> numbers0 { 3, 2, 5, 4, 1 };  
    pairProduct(numbers0, 10); // -> [1, 2]

    std::vector<int> numbers1 { 4, 7, 9, 2, 5, 1 };  
    pairProduct(numbers1, 5); // -> [4, 5]

    std::vector<int> numbers2 { 4, 7, 9, 2, 5, 1 };  
    pairProduct(numbers2, 35); // -> [1, 4]

    std::vector<int> numbers3 { 3, 2, 5, 4, 1 };
    pairProduct(numbers3, 10); // -> [1, 2]

    std::vector<int> numbers4 { 4, 6, 8, 2 };  
    pairProduct(numbers4, 16); // -> [2, 3]
};


//Hash Map Complexity:
    //n = numbers length
    
    //Time: O( n )
    //Space: O( n )