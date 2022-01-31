#include <string>

std::string greet(std::string s) {
    return "hey " + s;
}

void run() {
    greet("alvin");
    greet("jason");
    greet("how now brown cow");
}