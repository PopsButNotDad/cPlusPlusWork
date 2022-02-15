#include <vector>
#include <unordered_map>
#include <unordered_set>

//Write a function, hasCycle, that takes in an unordered map representing the adjacency list of a directed graph.
//The function should return a boolean indicating whether or not the graph contains a cycle.

bool hasCycle(std::unordered_map<char, std::vector<char>> graph) {
    
    return;
}

int main() {
    std::unordered_map<char, std::vector<char>> graph {
        { 'a', {'b'} },
        { 'b', {'c'} },
        { 'c', {'a'} }
    };
    hasCycle(graph); // -> 1 (true)

    std::unordered_map<char, std::vector<char>> graph1 {
        { 'a', {'b', 'c'} },
        { 'b', {'c'} },
        { 'c', {'d'} },
        { 'd', {} }
    };
    hasCycle(graph1); // -> 0 (false)

    std::unordered_map<char, std::vector<char>> graph2 {
        { 'a', {'b', 'c'} },
        { 'b', {} },
        { 'c', {} },
        { 'e', {'f'} },
        { 'f', {'e'} }
    };
    hasCycle(graph2); // -> 1 (true)

    std::unordered_map<char, std::vector<char>> graph3 {
        { 'q', {'r', 's'} },
        { 'r', {'t', 'u'} },
        { 's', {} },
        { 't', {} },
        { 'u', {} },
        { 'v', {'w'} },
        { 'w', {} },
        { 'x', {'w'} }
    };
    hasCycle(graph3); // -> 0 (false)

    std::unordered_map<char, std::vector<char>> graph4 {
        { 'a', {'b'} },
        { 'b', {'c'} },
        { 'c', {'a'} },
        { 'g', {} }
    };
    hasCycle(graph4); // -> 1 (true)
}

//Complexity
    //n = number of nodes
    //e = number of edges

    //Time: O( e )
    //Space: O( n )