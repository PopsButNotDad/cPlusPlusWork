#include <unordered_map>
#include <vector>
#include <string>
#include <stack>


//Depth First
void depthFirstPrint(std::unordered_map<std::string, std::vector<std::string>> graph, std::string start){
    std::stack<std::string> stack;

    stack.push(start);

    while(!stack.empty()){
        
    }

}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph {
        {"a", {"b", "c"} },
        {"b", {"d"} },
        {"c", {"e"} },
        {"d", {"f"} },
        {"e", { } },
        {"f", { } }
    };

    return 1;
}
