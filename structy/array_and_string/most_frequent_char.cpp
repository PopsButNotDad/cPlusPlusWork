#include <string>
#include <iostream>
#include <unordered_map>

//Write a function, mostFrequentChar, that atkes in a string as an argument. The function should return the most frequent
//character of the string. If there are ties, return the character that appears earlier in the string.

//You can assume that the input string is non-empty.

// function returns a char and takes in a string as an argument
char mostFrequentChar(std::string s) {
    //initialize the hash map
    std::unordered_map<char, int> count;
    //for each character in the string incremement the count by 1
        //this is automatically done because we initialized the map with an int value
    for (char ch : s) {
        count[ch] += 1;
    }
    //initialize a best variable to the null character
    char best = '\0';
    //for each character in the string check if the count of that character is larger than the count of the best variable
        //if it is then set the best variable to that character
    for (char ch : s) {
        if (count[ch] > count[best]){
            best = ch;
        }
    }
    //console log and return the best character
    std::cout << best << std::endl;
    return best;
};

int main() {
    mostFrequentChar("bookeeper"); // -> 'e'
    mostFrequentChar("david"); // -> 'd'
    mostFrequentChar("abby"); // -> 'b'
    mostFrequentChar("mississippi"); // -> 'i'
    mostFrequentChar("potato"); // -> 'o'
    mostFrequentChar("eleventennine"); // -> 'e'
    mostFrequentChar("riverbed"); // -> 'r'
};

//Complexity
    //n = string length

    //Time: O( n )
    //Space: O( n )