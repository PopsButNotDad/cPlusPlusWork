#include <unordered_map>
#include <vector>

//Write a function, largestComponent, that takes in an unordered_map representing the adjacency list of an undirected graph.
//The function should return the size of the largest connected component in the graph.


int largestComponent(std::unordered_map<int, std::vector<int>> graph) {
    // todo
    return;
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

    std::unordered_map<int, std::vector<int>> graph {
        { 1, {2} },
        { 2, {1, 8} },
        { 6, {7} },
        { 9, {8} },
        { 7, {6, 8} },
        { 8, {9, 7, 2} }
    };
    largestComponent(graph); // -> 6

    std::unordered_map<int, std::vector<int>> graph {
        { 3, {} },
        { 4, {6} },
        { 6, {4, 5, 7, 8} },
        { 8, {6} },
        { 7, {6} },
        { 5, {6} },
        { 1, {2} },
        { 2, {1} }
    };
    largestComponent(graph); // -> 5

    std::unordered_map<int, std::vector<int>> graph;
    largestComponent(graph); // -> 0

    std::unordered_map<int, std::vector<int>> graph {
        { 0, {4, 7} },
        { 1, {} },
        { 2, {} },
        { 3, {6} },
        { 4, {0} },
        { 6, {3} },
        { 7, {0} },
        { 8, {} }
    };
    largestComponent(graph); // -> 3
}

//Complexity
    //n = number of nodes
    //e = number of edges

    //Time: O( e )
    //Space: O( n )