#include <array>
#include <vector>
#include <iostream>
#include <unordered_map>

//Write a function, pairSum, that takes in a vector of numbers and a target sum as arguments. The function should return
//a std::array containing a pair of indices whose elements sum to the given target. The indices returned must be unique.

//Be sure to return the indices, not the elements themselves. 

//There is guaranteed to be one such pair that sums to the target.

std::array<int, 2> pairSum(std::vector<int> numbers, int target) {

    //initialize the hash map, make sure to incluide the map above
    std::unordered_map<int, int> nums;

    //loop through the list of numbers
    for(int i = 0; i < numbers.size(); i+=1){
        //set variable of current to the list of numbers at i index
        int current = numbers[i];
        //set variable to the target minus the current numbers
        int complement = target - current;
        //if the hash map contains the complement number
        if(nums.count(complement) > 0){
            //then print out and return the hash map key value pair
            std::cout << nums[complement] << " , " << i << std::endl;
            return std::array<int, 2> { nums[complement],i };
        }
        //set the key of the hash map to the current number and have the value equal the index of the numbers list
        nums[current] = i;
    }

}

//BRUTE FORCE SOLUTION
//function takes vector and target in as arguments
std::array<int, 2> pairSumBrute(std::vector<int> numbers, int target) {
    //two nested for loops that iterate through the vector of numbers twice
    for(int i = 0; i < numbers.size(); i+=1){
        //initialize j so that it is always 1 bigger than i
        for(int j = i + 1; j < numbers.size(); j+=1){
            //if the numbers added together reach the target
            if ((numbers[i] + numbers[j]) == target){
                //print out and return the indices
                std::cout << i << " , " << j << std::endl;
                return std::array { i, j };
            }
        }
    }
};

int main () {

    std::vector<int> numbers0 { 3, 2, 5, 4, 1 };
    pairSum(numbers0, 8); // -> [0, 2]

    std::vector<int> numbers1 { 4, 7, 9, 2, 5, 1 };
    pairSum(numbers1, 5); // -> [0, 5]

    std::vector<int> numbers2 { 4, 7, 9, 2, 5, 1 };
    pairSum(numbers2, 3); // -> [3, 5] 

    std::vector<int> numbers3 { 1, 6, 7, 2 };
    pairSum(numbers3, 13); // -> [1, 2]

    std::vector<int> numbers4 { 9, 9 };
    pairSum(numbers4, 18); // -> [0, 1]

    std::vector<int> numbers { 6, 4, 2, 8 };
    pairSum(numbers, 12); // -> [1, 3]

};

//Brute Force Complexity:
    //n = array length

    //Time: O( n^2 )
    //Space: O( 1 )

//Hash Map Complexity: 
    //n = array length

    //Time: O( n )
    //Space: O( n )