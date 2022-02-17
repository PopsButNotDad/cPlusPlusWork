#include <vector>

//Write a function, sumPossible, that takes in an amount and a vector of positive numbers. The function should return a 
//boolean indicating whether or not it is possible to create the amount by summing numbers of the vector. You may reuse
//numbers of the vector as many times as necessary.

//You may assume the target amount is non-negative.

bool sumPossible(int amount, std::vector<int> numbers) {
    // todo
    return;
}

int main() {
    sumPossible(8, std::vector<int>{5, 12, 4}); // -> true, 4 + 4

    sumPossible(15, std::vector<int>{6, 2, 10, 19}); // -> false

    sumPossible(13, std::vector<int>{6, 2, 1}); // -> true

    sumPossible(103, std::vector<int>{6, 20, 1}); // -> true

    sumPossible(12, std::vector<int>{}); // -> false

    sumPossible(12, std::vector<int>{12}); // -> true

    sumPossible(0, std::vector<int>{}); // -> true

    sumPossible(271, std::vector<int>{10, 8, 265, 24}); // -> false

    sumPossible(2017, std::vector<int>{4, 2, 10}); // -> false

    sumPossible(13, std::vector<int>{3, 5}); // -> true
}

//Complexity:
    //

    //Time: 
    //Space: