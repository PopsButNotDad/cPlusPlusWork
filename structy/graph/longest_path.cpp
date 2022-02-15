#include <vector>
#include <unordered_map>

//Write a function, longestPath, that takes in an adjacency list for a directed acyclic graph. The function should return the
//length of the longest path within the graph. A path may start and end at any two nodes. The length of a path is 
//considered the number of edges in the path, not the number of nodes.

//helper function takes graph, node, and reference to unordered map distance
int exploreDistance(std::unordered_map<char, std::vector<char>> graph, char node, std::unordered_map<char, int> &distance) {
    //if the node appears in the unordered map return the distance (means we already hit it)
    if(distance.count(node) > 0){
        return distance[node];
    }
    //initialize max value variable
    int maxDistance = 0;
    //for every neighbor in the graph at that node
    for(char neighbor : graph[node]){
        //recursive leap of faith returns an int and save it inside a variable
        int neighborDistance = exploreDistance(graph, neighbor, distance);
        //if the neighbor distance is larger than the max distance
        if(neighborDistance > maxDistance){
            //set max distance to new "max"
            maxDistance = neighborDistance;
        }
    }
    //the distance map at that node is equal to 1 (including the self) plus the max from above.
    distance[node] =  1 + maxDistance;
    //return the value in the map at that node.
    return distance[node];
}
//main function takes a map of chars and vector of chars
int longestPath(std::unordered_map<char, std::vector<char>> graph) {
    //initialize the unordered map and call it distance
    std::unordered_map<char, int> distance;
    //for every pair inside the graph 
    for(auto pair : graph){
        //set node to the first bit of data in the pairs
        char node = pair.first;
        //set neighbor to the second bits of data in the pairs
        std::vector<char> neighbors = pair.second;
        //if the node has no neighbors 
        if(neighbors.size() == 0){
            //then we know the distance is 0
            distance[node] = 0;
        }
    }
    //for every pair in the graph
    for(auto pair : graph){
        //set node to the first bit of data 
        char node = pair.first;
        //run the helper function on that node
        exploreDistance(graph, node, distance);
    }
    //initialize more max value variable
    int max = 0;
    //for every pair in the distance map
    for(auto pair : distance){
        //if the second bit of data is larger than the max variable
        if(pair.second > max){
            //set the max variable to the new "max"
            max = pair.second;
        }
    }
    //return the max when finished.
    return max;
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