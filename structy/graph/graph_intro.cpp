#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <iostream>


//Depth First Iterative
void depthFirstPrintIt(std::unordered_map<std::string, std::vector<std::string>> graph, std::string start){
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

//Breadth First
void breadthFirstPrint(std::unordered_map<std::string, std::vector<std::string>> graph, std::string start){
    std::queue<std::string> queue;
    queue.push(start);
    while (!queue.empty()) {
        std::string current = queue.front();
        std::cout << current << std::endl;
        queue.pop();
        for(std::string neighbor : graph[current]){
            queue.push(neighbor);
        }
    }
}

//Recursive
void depthFirstPrint(std::unordered_map<std::string, std::vector<std::string>> graph, std::string current){
    std::cout << current << std::endl;
    for(std::string neighbor : graph[current]){
        depthFirstPrint(graph, neighbor);
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
