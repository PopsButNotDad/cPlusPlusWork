#include <vector>
#include <unordered_map>
#include <algorithm>

//Write a function, nonAdjacentSum, that takes in a vector of numbers as an argument. The function should return the maximum
//sum of non-adjacent elements in the vector. There is no limit on how manu elements can be taken into the sum as long as
//they are not adjacent.

// For example, given:

// { 2, 4, 5, 12, 7 }

// The maximum non-adjacent sum is 16, because 4 + 12. 
// 4 and 12 are not adjacent in the vector.

int nonAdjacentSum(std::vector<int> nums, int i, std::unordered_map<int, int> &memo) {
    if(memo.count(i) > 0){
        return memo[i];
    }
    if(i >= nums.size()){
        return 0;
    }

    int include = nums[i] + nonAdjacentSum(nums, i + 2, memo);
    int exclude = nonAdjacentSum(nums, i + 1, memo);
    memo[i] = std::max(include, exclude);
    return memo[i];
}

int nonAdjacentSum(std::vector<int> nums) {
    std::unordered_map<int, int> memo;
    return nonAdjacentSum(nums, 0, memo);
}

int main() {
    std::vector<int> nums { 2, 4, 5, 12, 7 };
    nonAdjacentSum(nums); // -> 16
    
    std::vector<int> nums1 { 7, 5, 5, 12 };
    nonAdjacentSum(nums1); // -> 19
    
    std::vector<int> nums2 { 7, 5, 5, 12, 17, 29 };
    nonAdjacentSum(nums2); // -> 48
    
    std::vector<int> nums3 { 
        72, 62, 10,  6, 20, 19, 42,
        46, 24, 78, 30, 41, 75, 38,
        23, 28, 66, 55, 12, 17, 9,
        12, 3, 1, 19, 30, 50, 20
    };
    nonAdjacentSum(nums3); // -> 488
    
    std::vector<int> nums4 { 
        72, 62, 10,  6, 20, 19, 42, 46, 24, 78,
        30, 41, 75, 38, 23, 28, 66, 55, 12, 17,
        83, 80, 56, 68,  6, 22, 56, 96, 77, 98,
        61, 20,  0, 76, 53, 74,  8, 22, 92, 37,
        30, 41, 75, 38, 23, 28, 66, 55, 12, 17,
        72, 62, 10,  6, 20, 19, 42, 46, 24, 78,
        42
    };
    nonAdjacentSum(nums4); // -> 1465
}

//Complexity
    //n = length of numbers

    //Time: O( n )
    //Space: O( n )