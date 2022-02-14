#include <unordered_map>
#include <vector>
#include <unordered_set>

//Write a function, connectedComponentsCount, that takes in an unordered map representing the adjacency list for an
//undirected graph. The function should return the number of connected components within the graph.

//recursive
bool explore(std::unordered_map<int, std::vector<int>> graph, int node, std::unordered_set<int> &visited) {
    if(visited.count(node) > 0){
        return false;
    }
    visited.insert(node);
    for(int neighbor : graph[node]){
        explore(graph, neighbor, visited);
    }
    return true;
}

int connectedComponentsCount(std::unordered_map<int, std::vector<int>> graph) {
    std::unordered_set<int> visited;
    int count = 0;
    for(auto pair : graph){
        int node = pair.first;
        if(explore(graph, node, visited)== true){
            count += 1;
        }
    }
    return count;
}

int main() {
    std::unordered_map<int, std::vector<int>> graph {
    { 0, { 8, 1, 5 } },
    { 1, { 0 } },
    { 5, { 0, 8 } },
    { 8, { 0, 5 } },
    { 2, { 3, 4 } },
    { 3, { 2, 4 } },
    { 4, { 3, 2 } }
    };
    connectedComponentsCount(graph); // -> 2

    std::unordered_map<int, std::vector<int>> graph1 {
    { 1, { 2 } },
    { 2, { 1, 8 } },
    { 6, { 7 } },
    { 9, { 8 } },
    { 7, { 6, 8 } },
    { 8, { 9, 7, 2 } }
    };
    connectedComponentsCount(graph1); // -> 1

    std::unordered_map<int, std::vector<int>> graph2 {
    { 3, { } },
    { 4, { 6 } },
    { 6, { 4, 5, 7, 8 } },
    { 8, { 6 } },
    { 7, { 6 } },
    { 5, { 6 } },
    { 1, { 2 } },
    { 2, { 1 } }
    };
    connectedComponentsCount(graph2); // -> 3

    std::unordered_map<int, std::vector<int>> graph3;
    connectedComponentsCount(graph3); // -> 0

    std::unordered_map<int, std::vector<int>> graph4 {
    { 0, { 4, 7 } },
    { 1, { } },
    { 2, { } },
    { 3, { 6 } },
    { 4, { 0 } },
    { 6, { 3 } },
    { 7, { 0 } },
    { 8, { } },
    };
    connectedComponentsCount(graph4); // -> 5

}

//Complextity 
    //n = number of nodes
    //e = number of edges

    //Time: O( e )
    //Space: O( n )