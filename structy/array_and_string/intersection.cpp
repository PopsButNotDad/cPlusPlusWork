#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

//Write a function, intersection, that takes in two vectors, a,b, as arguments. The function should return a new vector
//containing elements that are in both of the two vectors.

//You may assume that each input vector does not contain duplicate elements.

std::vector<int> intersection(std::vector<int> a, std::vector<int> b) {
    
    //unordered set offers constant look up time
    std::unordered_set<int> setA;
    for(int el : a) {
        setA.insert(el);
    }
    //once again like the map use count to check if it exists inside the set and push it into the vector
    std::vector<int> result;
    for(int el : b){
        if(setA.count(el) > 0){
            result.push_back(el);
        }
    }

    //return it when finished
    for(int re : result){
        std::cout<<re << " ," << std::endl;;
    }
    return result;
}

//BRUTE FORCE METHOD
std::vector<int> intersectionBrute(std::vector<int> a, std::vector<int> b) {
    std::vector<int> result;
    for(int el1 : a) {
        for(int el2 : b) {
            if(el1 == el2){
                result.push_back(el1);
            }
        }
    }
    return result;
}


int main () {
    std::vector<int> a1 {4,2,1,6};
    std::vector<int> b1 {3,6,9,2,10};
    intersection(a1, b1); // -> [2,6]

    std::vector<int> a0 {2,4,6};
    std::vector<int> b0 {4,2};
    intersection(a0, b0); // -> [2,4]

    std::vector<int> a2 {4,2,1};
    std::vector<int> b2 {1,2,4,6};
    intersection(a2, b2); // -> [1,2,4]

    std::vector<int> a3 {0,1,2};
    std::vector<int> b3 {10,11};
    intersection(a3, b3); // -> []

    std::vector<int> a4;
    std::vector<int> b4;
    for (int i = 0; i < 32000; i += 1) {
        a4.push_back(i);
        b4.push_back(i);
    }
    intersection(a4, b4); // -> [0,1,2,3,..., 31999]
};


//Brute Force Complexity
    //n = array1 length
    //m = array2 length

    //Time: O( n*m )
    //Space:O( min(n, m) )

//Set Method Complexity:
    //n = array1 length
    //m = array2 length

    //Time: O( n+m )
    //Space: O( n )