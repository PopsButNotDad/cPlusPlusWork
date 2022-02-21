#include <unordered_map>
//Write a function, summingSquares, that takes a target number as an argument. The function should return the minimum
//number of perfect squares that sum to the target. A perfect square is a number of the form (i*i) where i >= 1.

//for example: 1, 4, 9, 16 are perfect squares but 8 is not a perfect square.

//Given 12:
// summingSquares(12) -> 3
// The minimum squares required for 12 is three, by doing 4 + 4 + 4.
// Another way to make 12 is 9 + 1 + 1 + 1, but that requires four perfect squares.

int summingSquares(int n) {
    // todo
    return;
}

int main() {
    summingSquares(8); // -> 2

    summingSquares(9); // -> 1

    summingSquares(12); // -> 3

    summingSquares(1); // -> 1

    summingSquares(31); // -> 4

    summingSquares(50); // -> 2

    summingSquares(68); // -> 2

    summingSquares(87); // -> 4
}

//Complexity:
    //
    //

    //Time:
    //Space: