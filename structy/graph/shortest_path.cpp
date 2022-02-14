#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
#include <unordered_set>

//Write a function, shortestPath, that takes in a vector of edges for an undirected graph and two nodes (nodeA, nodeB).
//The function should return the length of the shortest path between A and B. Consider the length as the number of edges
//in the path, not the number of nodes. If there is no path between A and B, then return -1.

std::unordered_map<std::string, std::vector<std::string>> makeGraph(std::vector<std::tuple<std::string, std::string>> edges) {
    std::unordered_map<std::string, std::vector<std::string>> graph;

    for(auto edge : edges){
        auto [a, b] = edge;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    return graph;
}

int shortestPath(std::vector<std::tuple<std::string, std::string>> edges, std::string nodeA, std::string nodeB) {
    std::unordered_map<std::string, std::vector<std::string>> graph = makeGraph(edges);
    std::unordered_set<std::string> visited;


    return;
}

int main() {
    std::vector<std::tuple<std::string, std::string>> edges {
    {"w", "x"},
    {"x", "y"},
    {"z", "y"},
    {"z", "v"},
    {"w", "v"}
    };
    shortestPath(edges, "w", "z"); // -> 2

    std::vector<std::tuple<std::string, std::string>> edges1 {
    {"w", "x"},
    {"x", "y"},
    {"z", "y"},
    {"z", "v"},
    {"w", "v"}
    };
    shortestPath(edges1, "y", "x"); // -> 1

    std::vector<std::tuple<std::string, std::string>> edges2 {
    {"a", "c"},
    {"a", "b"},
    {"c", "b"},
    {"c", "d"},
    {"b", "d"},
    {"e", "d"},
    {"g", "f"}
    };
    shortestPath(edges2, "a", "e"); // -> 3

    std::vector<std::tuple<std::string, std::string>> edges3 {
    {"a", "c"},
    {"a", "b"},
    {"c", "b"},
    {"c", "d"},
    {"b", "d"},
    {"e", "d"},
    {"g", "f"}
    };
    shortestPath(edges3, "e", "c"); // -> 2

    std::vector<std::tuple<std::string, std::string>> edges4 {
    {"a", "c"},
    {"a", "b"},
    {"c", "b"},
    {"c", "d"},
    {"b", "d"},
    {"e", "d"},
    {"g", "f"}
    };
    shortestPath(edges4, "b", "g"); // -> -1

    std::vector<std::tuple<std::string, std::string>> edges5 {
    {"c", "n"},
    {"c", "e"},
    {"c", "s"},
    {"c", "w"},
    {"w", "e"},
    };
    shortestPath(edges5, "w", "e"); // -> 1

    std::vector<std::tuple<std::string, std::string>> edges6 {
    {"c", "n"},
    {"c", "e"},
    {"c", "s"},
    {"c", "w"},
    {"w", "e"},
    };
    shortestPath(edges6, "n", "e"); // -> 2

    std::vector<std::tuple<std::string, std::string>> edges7 {
    {"m", "n"},
    {"n", "o"},
    {"o", "p"},
    {"p", "q"},
    {"t", "o"},
    {"r", "q"},
    {"r", "s"}
    };
    shortestPath(edges7, "m", "s"); // -> 6
}

//Complexity
    //n = 
    //e = 

    //Time: 
    //Space: