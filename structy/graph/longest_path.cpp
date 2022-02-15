#include <vector>
#include <unordered_map>

//Write a function, longestPath, that takes in an adjacency list for a directed acyclic graph. The function should return the
//length of the longest path within the graph. A path may start and end at any two nodes. The length of a path is 
//considered the number of edges in the path, not the number of nodes.


int longestPath(std::unordered_map<char, std::vector<char>> graph) {
    std::unordered_map<char, int> distance;
    for(auto pair : graph){
        char node = pair.first;
        std::vector<char> neighbors = pair.second;
        if(neighbors.size() == 0){
            distance[node] = 0;
        }
    }

    return;
}

int main() {
    std::unordered_map<char, std::vector<char>> graph {
        { 'a', {'c', 'b'} },
        { 'b', {'c'} },
        { 'c', {} }
    };
    longestPath(graph); // -> 2

    std::unordered_map<char, std::vector<char>> graph {
        { 'a', {'c', 'b'} },
        { 'b', {'c'} },
        { 'c', {} },
        { 'q', {'r'} },
        { 'r', {'s', 'u', 't'} },
        { 's', {'t'} },
        { 't', {'u'} },
        { 'u', {} }
    };
    longestPath(graph); // -> 4

    std::unordered_map<char, std::vector<char>> graph {
        { 'h', {'i', 'j', 'k'} },
        { 'g', {'h'} },
        { 'i', {} },
        { 'j', {} },
        { 'k', {} },
        { 'x', {'y'} },
        { 'y', {} }
    };
    longestPath(graph); // -> 2

    std::unordered_map<char, std::vector<char>> graph {
        { 'a', {'b'} },
        { 'b', {'c'} },
        { 'c', {} },
        { 'e', {'f'} },
        { 'f', {'g'} },
        { 'g', {'h'} },
        { 'h', {} }
    };
    longestPath(graph); // -> 3
}

//Complexity
    //n = number of nodes 
    //e = number of edges

    //Time: O( e )
    //Space: O( n )