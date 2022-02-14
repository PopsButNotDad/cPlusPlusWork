#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

//Write a function, connectedComponentsCount, that takes in an unordered map representing the adjacency list for an
//undirected graph. The function should return the number of connected components within the graph.

int connectedComponentsCount(std::unordered_map<int, std::vector<int>> graph) {
    // todo
    return;
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