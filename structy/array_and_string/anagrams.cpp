#include <string>
#include <iostream>
#include <unordered_map>

//Write a function, anagrams, that takes in two strings as arguments. The fucntion should return a boolean indicating
//whether or not the strings are anagrams. Anagrams are strings that contain the same characters, but in any order.


std::unordered_map<char, int> charCount(std::string s){
    std::unordered_map<char, int> count;

    for(char ch : s){
        count[ch] +=1;
    }

    return count;
}




bool anagrams(std::string s1, std::string s2) {
    std::cout << (charCount(s1) == charCount(s2)) << std::endl;
    return charCount(s1) == charCount(s2);
}

int main () {
    anagrams("restful", "fluster"); // -> true
    anagrams("cats", "tocs"); // -> false
    anagrams("monkeyswrite", "newyorktimes"); // -> true
    anagrams("paper", "reapa"); // -> false
    anagrams("elbow", "below"); // -> true
    anagrams("tax", "taxi"); // -> false
    anagrams("taxi", "tax"); // -> false
    anagrams("night", "thing"); // -> true
    anagrams("abbc", "aabc"); // -> false
};

//Complexity
    //n = string1 length
    //m = string 2 length

    //Time: O( n+m )
    //Space: ~O( n+m )