#include <string>


//Write a function, uncompress, that takes in a string as an argument. 
//The input string will be formattted into multiple groups according to the following pattern:

//<number><char>
//for example, '2c' or '3a'.

//The fucntion should return an uncompressed version of the string where each 'char' of a group is repeated 'number'
//times consecutively. You may assume that the input string is well-formed according to the previously mentioned
//pattern.

//brute force solution
//uncompress takes a string s as an argument
std::string uncompress1(std::string s) {
    //want to initialize a string of numbers to check against
    std::string numbers = "0123456789";
    //want to initialize a result to return;
    std::string result = "";
    //initialize the count variables
    int i = 0;
    int j = 0;
    //while j is less than the argument strings length
    while(j < s.length()){
        //if the jth index in the s string is not inside the numbers string then increment j
        if(numbers.find(s[j]) != std::string::npos){
            j += 1;
        //else when it is inside the numbers string
        } else {
            //set a variable count to the substring from i to j in the argument string
            int count = std::stoi(s.substr(i, j));
            //loop through everything up to the count
            for(int n = 0; n < count; n+= 1){
                //concatenate the result string with s[j]
                result += s[j];
            }
            //increment the variables and then set them to the same pointers
            j += 1;
            i = j;
        }
    }
    //return the result
    return result;
};


//upgraded answer
std::string uncompress(std::string s) {
    std::string numbers = "0123456789";
    std::string result = "";
    int i = 0;
    int j = 0;
    while(j < s.length()){
        if(numbers.find(s[j]) != std::string::npos){
            j += 1;
        } else {
            int count = std::stoi(s.substr(i, j));
            //built in method to add s[j] to the string count number of times
            result += std::string(count, s[j]);
            j += 1;
            i = j;
        }
    }


    return result;
};

int main(){
    uncompress("2c3a1t"); // -> "ccaaat"
    uncompress("4s2b"); // -> "ssssbb"
    uncompress("2p1o5p"); // -> "ppoppppp"
    uncompress("3n12e2z"); // -> "nnneeeeeeeeeeeezz"
    uncompress("127y"); 
        // ->"yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
            //yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
            //yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy"
}


//Complexity
    //n = # of groups
    //m = max number of any group

    //Time: O( nm )
    //Space: O( nm )