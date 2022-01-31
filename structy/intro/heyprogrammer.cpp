#include <string>

std::string greet(std::string s) {
    return "hey " + s;
}

int main() {
    greet("alvin");
    greet("jason");
    greet("how now brown cow");
}