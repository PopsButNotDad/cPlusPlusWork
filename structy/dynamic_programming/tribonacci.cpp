#include <unordered_map>

//Write a function, tribonacci, that takes in a number argument, n, and returns the n-th number of the tribonacci sequence.
//The 0-th and 1-st numbers of the sequence are both 0.

//To generate further numbers of the sequence, calculate the sum of previous three numbers.

//Solve this recursively.

int tribonacci(int n, std::unordered_map<int, int> &memo) {
    if(memo.count(n) > 0){
        return memo[n];
    }

    if(n == 0 || n == 1){
        return 0;
    }

    if(n == 2){
        return 1;
    }

    memo[n] = tribonacci(n-1, memo) + tribonacci(n-2, memo) + tribonacci(n-3, memo);

    return memo[n];
}

int tribonacci(int n) {
    std::unordered_map<int, int> memo;
    return tribonacci(n, memo);
}

int main(){
    tribonacci(0); // -> 0
    tribonacci(1); // -> 0
    tribonacci(2); // -> 1
    tribonacci(5); // -> 4
    tribonacci(7); // -> 13
    tribonacci(14); // -> 927
    tribonacci(20); // -> 35890
    tribonacci(37); // -> 1132436852
}

//Complexity
    //n = number of nodes

    //Time: O( n )
    //Space: O( n )