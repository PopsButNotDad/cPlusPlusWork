#include <string>
#include <iostream>
#include <unordered_map>

//Write a function, anagrams, that takes in two strings as arguments. The fucntion should return a boolean indicating
//whether or not the strings are anagrams. Anagrams are strings that contain the same characters, but in any order.

//unordered map function takes a string as an argument
std::unordered_map<char, int> charCount(std::string s){
    //initialize the hashmap (make sure to include the library uptop)
    std::unordered_map<char, int> count;

    //for each character in the string
    for(char ch : s){
        //increment the count of the character by 1 
            //since the map was initialized with int this will auto happen
        count[ch] +=1;
    }
    //return the map
    return count;
}

//function anagrams takes two strings as arguments and returns a boolean
bool anagrams(std::string s1, std::string s2) {
    //console log the boolean result if the counts of both strings are equal
    std::cout << (charCount(s1) == charCount(s2)) << std::endl;
    //return the same result
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