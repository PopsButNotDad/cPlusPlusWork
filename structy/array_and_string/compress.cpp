#include <string>
#include <iostream>


//Write a function, compress, that takes in a string as an argument. The function should return a compressed version
//of the string where consecutive occurrences of the same characters are compressed into the number of occurrences
//followers by the character. Single character occurrences should not be changed.

//'aaa' compresses to '3a'
//'cc' compresses to '2c'
//'t' should remain as 't'

//You can assume that the input only contains alphabetic characters.

//compress function returns a string and uses a string as an argument
std::string compress(std::string s) {
    //initialize what we will be returning
    std::string result ="";
    //initialize the pointer variables
    int i = 0;
    int j = 0;
    //while j is less than or equal to the length of the argument string
        //using less than or equal to because all strings in C++ end with a null character
    while (j <= s.length()){
        //if the characters between the two pointers are equal then incremenent the j pointer
        if(s[i] == s[j]){
            j+=1;
            //else if the characters between the two pointers are different
        } else {
            //set the count variable to the difference between j and i
            int count = j - i;
            //if the count is only 1 then add just the letter to the result but not the count
            if(count == 1) {
                result += s[i];
            // else if the count is more than 1 then add the count and the character to the result string
            } else {
                result += std::to_string(count) + s[i];
            }
            //once complete set i pointer to where j is
            i = j;
        }
    }
    //output the result and return it
    std::cout << result << std::endl;
    return result;
};

int main() {
    compress("ccaaatsss"); // -> "2c3at3s"
    compress("ssssbbz"); // -> "4s2bz"
    compress("ppoppppp"); // -> "2po5p"
    compress("nnneeeeeeeeeeeezz"); // -> "3n12e2z"
    compress("yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy"); 
    // -> "127y"
};

//Complexity
    //n = string length

    //Time: O( n )
    //Space: O( n )