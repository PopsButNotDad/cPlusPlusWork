#include <unordered_map>

//Write a function, fib, that takes in a number as an argument, n, and returns the n-th number of the fibonacci sequence.
//The 0-th number of the sequence is 0. The 1-st number of the sequence is 1. To generate further numbers of the sequence,
//calculate the sum of the previous two numbers.

int fib(int n, std::unordered_map<int, int> &memo) {
    if(memo.count(n) > 0){
        return memo[n];
    }

    if( n < 2 ){
        return n;
    }
    memo[n] =  fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}

int fib(int n) {
    std::unordered_map<int, int> memo;
    return fib(n, memo);
}

int main() {
    fib(0); // -> 0

    fib(1); // -> 1

    fib(2); // -> 1

    fib(3); // -> 2

    fib(4); // -> 3

    fib(5); // -> 5

    fib(35); // -> 9227465

    fib(46); // -> 1836311903

}

//Complexity
    //n = number of nodes

    //Time: O( n )
    //Space: O( n )