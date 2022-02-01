#include <iostream>
#include <math.h>


//is prime function takes an integer n as an argument
bool isPrime(int n){

    if(n < 2){
        std::cout << false << std::endl;
        return false;
    }
    //want to start i at 2 because prime numbers are divisible by 1, want it to only go up to but not including sqrt
    // of n because of cool math logic and we want to increment i by 1
    for (int i = 2; i <= sqrt(n); i += 1){
        //if n modulo i equals 0 then print out false and return false as it is not a prime number
        if ( n % i == 0){
            std::cout << false << std::endl;
            return false;
        }
    }
    //once the loop is complete and the above conditions weren't met then print out true and return true;
    std::cout << true << std:: endl;
    return true;
}

int main() {
    isPrime(2); // -> 1 (true)
    isPrime(3); // -> 1 (true)
    isPrime(4); // -> 0 (false)
    isPrime(5); // -> 1 (true)
    isPrime(6); // -> 0 (false)
    isPrime(7); // -> 1 (true)
    isPrime(8); // -> 0 (false)
    isPrime(25); // -> 0 (false)
    isPrime(31); // -> 1 (true)
    isPrime(2017); // -> 1 (true)
    isPrime(2048); // -> 0 (false)
    isPrime(1); // -> 0 (false)
    isPrime(713); // -> 0 (false)
}