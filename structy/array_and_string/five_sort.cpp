#include <vector>
#include <iostream>

//Write a function, fiveSort, that takes in a vector of numbers as an argument. The function should rearrange elements
//of the vector such that all 5s appear at the end. Your function should perform this operation in-place by mutating
//the original vector. The function should return the vector. 

//Elements that are not 5 can appear in any order in the output, as long as all 5s are at the end of the vector.


//since this has to be done in place we want to make sure to take in argument as reference and return it as reference.
std::vector<int>& fiveSort(std::vector<int> &numbers) {
    int i = 0;
    int j = numbers.size() - 1;

    while(i < j){
        if(numbers[j] == 5){
            j-=1;
        } else if (numbers[i] != 5){
            i +=1;
        } else {
            //use a temp variable to make the swapping easier
            int tmp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = tmp;
        }
    }
    return numbers;
}

int main() {
    std::vector<int> numbers0 {12, 5, 1, 5, 12, 7};
    fiveSort(numbers0);
    // -> [12, 7, 1, 12, 5, 5] 

    std::vector<int> numbers1 {5, 2, 5, 6, 5, 1, 10, 2, 5, 5};
    fiveSort(numbers1);
    // -> [2, 2, 10, 6, 1, 5, 5, 5, 5, 5] 

    std::vector<int> numbers2 {5, 5, 5, 1, 1, 1, 4};
    fiveSort(numbers2);
    // -> [4, 1, 1, 1, 5, 5, 5] 

    std::vector<int> numbers3 {5, 5, 6, 5, 5, 5, 5};
    fiveSort(numbers3);
    // -> [6, 5, 5, 5, 5, 5, 5] 

    std::vector<int> numbers3 {5, 1, 2, 5, 5, 3, 2, 5, 1, 5, 5, 5, 4, 5};
    fiveSort(numbers3);
    // -> [4, 1, 2, 1, 2, 3, 5, 5, 5, 5, 5, 5, 5, 5] 
}

//Complexity:
    //n = array length

    //Time: O( n )
    //Space: O( 1 )