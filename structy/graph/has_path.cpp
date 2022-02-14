#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <queue>


//Write a function, hasPath, that takes in an unordered map representing the adjacency list of a directed acyclic graph
//and two nodes (src, dst). The function should return a boolean indicating whether or not there exists a directed path
//between the source and destination nodes.


bool hasPath(std::unordered_map<std::string, std::vector<std::string>> graph, std::string src, std::string dst) {
    
    return;
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

    std::unordered_map<std::string, std::vector<std::string>> graph {
    { "f", { "g", "i" } },
    { "g", {"h"} },
    { "h", {} },
    { "i", {"g", "k"} },
    { "j", {"i"} },
    { "k", {} }
    };

    hasPath(graph, "f", "j"); // 0 (false)

    std::unordered_map<std::string, std::vector<std::string>> graph {
    { "f", {"g", "i"} },
    { "g", {"h"} },
    { "h", {} },
    { "i", {"g", "k"} },
    { "j", {"i"} },
    { "k", {} }
    };

    hasPath(graph, "i", "h"); // 1 (true)

    std::unordered_map<std::string, std::vector<std::string>> graph {
    { "v", {"x", "w"} },
    { "w", {} },
    { "x", {} },
    { "y", {"z"} },
    { "z", {} } 
    };

    hasPath(graph, "v", "w"); // 1 (true)

    std::unordered_map<std::string, std::vector<std::string>> graph {
    { "v", {"x", "w"} },
    { "w", {} },
    { "x", {} },
    { "y", {"z"} },
    { "z", {} } 
    };

    hasPath(graph, "v", "z"); // 0 (false)
}

//Complexity 
    //n = number of nodes
    //n^2 = number of edges

    //Time: O( n^2 )
    //Space: O( n )