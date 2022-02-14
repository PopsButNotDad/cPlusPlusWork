#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <iostream>


//Depth First
void depthFirstPrint(std::unordered_map<std::string, std::vector<std::string>> graph, std::string start){
    std::stack<std::string> stack;

    stack.push(start);

    while(!stack.empty()){
        std::string current = stack.top();
        std::cout << current << std::endl;
        stack.pop();
        for(std::string neighbor : graph[current]){
            stack.push(neighbor);
        }
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

    depthFirstPrint(graph, "a");
    return 1;
}
