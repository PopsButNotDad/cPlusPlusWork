#include <unordered_map>
#include <vector>
#include <unordered_set>

//Write a function, largestComponent, that takes in an unordered_map representing the adjacency list of an undirected graph.
//The function should return the size of the largest connected component in the graph.

//recursive
int explore(std::unordered_map<int, std::vector<int>> graph, int node, std::unordered_set<int> &visited){
    if(visited.count(node) > 0){
        return 0;
    }
    visited.insert(node);
    int totalSize = 1;
    for(int neighbor : graph[node]){
        totalSize += explore(graph, neighbor, visited);
    }
    return totalSize;
}

int largestComponent(std::unordered_map<int, std::vector<int>> graph) {
    std::unordered_set<int> visited;
    int largest = 0;
    for(auto pair : graph){
        int node = pair.first;
        int currentSize = explore(graph, node, visited);
        if(currentSize > largest){
            largest = currentSize;
        }
    }
    return largest;
}

int main() {
    std::unordered_map<int, std::vector<int>> graph {
        { 0, {8, 1, 5} },
        { 1, {0} },
        { 5, {0, 8} },
        { 8, {0, 5} },
        { 2, {3, 4} },
        { 3, {2, 4} },
        { 4, {3, 2} }
    };
    largestComponent(graph); // -> 4

    std::unordered_map<int, std::vector<int>> graph1 {
        { 1, {2} },
        { 2, {1, 8} },
        { 6, {7} },
        { 9, {8} },
        { 7, {6, 8} },
        { 8, {9, 7, 2} }
    };
    largestComponent(graph1); // -> 6

    std::unordered_map<int, std::vector<int>> graph2 {
        { 3, {} },
        { 4, {6} },
        { 6, {4, 5, 7, 8} },
        { 8, {6} },
        { 7, {6} },
        { 5, {6} },
        { 1, {2} },
        { 2, {1} }
    };
    largestComponent(graph2); // -> 5

    std::unordered_map<int, std::vector<int>> graph3;
    largestComponent(graph3); // -> 0

    std::unordered_map<int, std::vector<int>> graph4 {
        { 0, {4, 7} },
        { 1, {} },
        { 2, {} },
        { 3, {6} },
        { 4, {0} },
        { 6, {3} },
        { 7, {0} },
        { 8, {} }
    };
    largestComponent(graph4); // -> 3
}

//Complexity
    //n = number of nodes
    //e = number of edges

    //Time: O( e )
    //Space: O( n `)