#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <queue>


//Write a function, hasPath, that takes in an unordered map representing the adjacency list of a directed acyclic graph
//and two nodes (src, dst). The function should return a boolean indicating whether or not there exists a directed path
//between the source and destination nodes.

//breadth first
// bool hasPath(std::unordered_map<std::string, std::vector<std::string>> graph, std::string src, std::string dst) {
//     std::queue<std::string> queue;

//     queue.push(src);

//     while(!queue.empty()){
//         std::string current = queue.front();
//         queue.pop();
//         if(current == dst){
//             return true;
//         }

//         for(std::string neighbor : graph[current]){
//             queue.push(neighbor);
//         }
//     }
//     return false;
// }

//depth first iterative
// bool hasPath(std::unordered_map<std::string, std::vector<std::string>> graph, std::string src, std::string dst) {
//     std::stack<std::string> stack;

//     stack.push(src);

//     while(!stack.empty()){
//         std::string current = stack.top();
//         stack.pop();
//         if(current == dst){
//             return true;
//         }

//         for(std::string neighbor : graph[current]){
//             stack.push(neighbor);
//         }
//     }
//     return false;
// }

//recursive
bool hasPath(std::unordered_map<std::string, std::vector<std::string>> graph, std::string src, std::string dst) {
    if (src == dst){
        return true;
    }

    for ( std::string neighbor : graph[src]){
        if (hasPath(graph, neighbor, dst) == true){
            return true;
        }
    }

    return false;
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph {
    { "f", {"g", "i"} },
    { "g", {"h"} },
    { "h", {} },
    { "i", {"g", "k"} },
    { "j", {"i"} },
    { "k", {} }
    };

    hasPath(graph, "f", "k"); // 1 (true)  

    std::unordered_map<std::string, std::vector<std::string>> graph1 {
    { "f", { "g", "i" } },
    { "g", {"h"} },
    { "h", {} },
    { "i", {"g", "k"} },
    { "j", {"i"} },
    { "k", {} }
    };

    hasPath(graph1, "f", "j"); // 0 (false)

    std::unordered_map<std::string, std::vector<std::string>> graph2 {
    { "f", {"g", "i"} },
    { "g", {"h"} },
    { "h", {} },
    { "i", {"g", "k"} },
    { "j", {"i"} },
    { "k", {} }
    };

    hasPath(graph2, "i", "h"); // 1 (true)

    std::unordered_map<std::string, std::vector<std::string>> graph3 {
    { "v", {"x", "w"} },
    { "w", {} },
    { "x", {} },
    { "y", {"z"} },
    { "z", {} } 
    };

    hasPath(graph3, "v", "w"); // 1 (true)

    std::unordered_map<std::string, std::vector<std::string>> graph4 {
    { "v", {"x", "w"} },
    { "w", {} },
    { "x", {} },
    { "y", {"z"} },
    { "z", {} } 
    };

    hasPath(graph4, "v", "z"); // 0 (false)
}

//Complexity 
    //n = number of nodes
    //n^2 = number of edges

    //Time: O( n^2 )
    //Space: O( n )