#include <vector>
#include <unordered_map>

//Write a function, minChange, that takes in an amount and a vector of coins. The function should return the minimum number
//of coins required to create the amount. You may use each coin as many times as necessary.

//If it is not possible to create the amount, then return -1.

int minChange(int amount, std::vector<int> coins) {
    // todo
    return;
}

int main() {
    minChange(8, std::vector<int>{1, 5, 4, 12}); // -> 2, because 4+4 is the minimum coins possible

    minChange(13, std::vector<int>{1, 9, 5, 14, 30}); // -> 5

    minChange(23, std::vector<int>{2, 5, 7}); // -> 4

    minChange(102, std::vector<int>{1, 5, 10, 25}); // -> 6

    minChange(200, std::vector<int>{1, 5, 10, 25}); // -> 8

    minChange(2017, std::vector<int>{4, 2, 10}); // -> -1

    minChange(271, std::vector<int>{10, 8, 265, 24}); // -> -1

    minChange(0, std::vector<int>{4, 2, 10}); // -> 0

    minChange(0, std::vector<int>{}); // -> 0
}

//Complexity: 
    //a = amount
    //c = coins

    //Time: O( a*c )
    //space: O( n )
