#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
#include <unordered_set>

//Write a function, undirectedPath, that takes in a vector of edges for an undirected graph and two nodes (nodeA, nodeB).
//The function should return a boolean indicating whether or not there exists a path between nodeA and nodeB.

//recursive
std::unordered_map<std::string, std::vector<std::string>> makeGraph(std::vector<std::tuple<std::string, std::string>> edges){
    std::unordered_map<std::string, std::vector<std::string>> graph;
    for(auto edge : edges){
        auto [a, b] = edge;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    return graph;
}

bool explore(std::unordered_map<std::string, std::vector<std::string>> graph, std::string src, std::string dst, std::unordered_set<std::string> &visited) {
    if(src == dst){
        return true;
    }

    if(visited.count(src) > 0){
        return false;
    } 

    visited.insert(src);

    for(std::string neighbor : graph[src]){
        if(explore(graph, neighbor, dst, visited) == true){
            return true;
        }
    }
    return false;
}

bool undirectedPath(std::vector<std::tuple<std::string, std::string>> edges, std::string src, std::string dst) {
    std::unordered_map<std::string, std::vector<std::string>> graph = makeGraph(edges);
    std::unordered_set<std::string> visited;
    return explore(graph, src, dst, visited);
}

int main() {
std::vector<std::tuple<std::string, std::string>> edges {
  {"i", "j"},
  {"k", "i"},
  {"m", "k"},
  {"k", "l"},
  {"o", "n"}
};

undirectedPath(edges, "j", "m"); // -> 1 (true)

std::vector<std::tuple<std::string, std::string>> edges1 {
  {"i", "j"},
  {"k", "i"},
  {"m", "k"},
  {"k", "l"},
  {"o", "n"}
};

undirectedPath(edges1, "m", "j"); // -> 1 (true)

std::vector<std::tuple<std::string, std::string>> edges2 {
  {"i", "j"},
  {"k", "i"},
  {"m", "k"},
  {"k", "l"},
  {"o", "n"}
};

undirectedPath(edges2, "l", "j"); // -> 1 (true)

std::vector<std::tuple<std::string, std::string>> edges3 {
  {"i", "j"},
  {"k", "i"},
  {"m", "k"},
  {"k", "l"},
  {"o", "n"}
};

undirectedPath(edges3, "k", "o"); // -> 0 (false)

std::vector<std::tuple<std::string, std::string>> edges4 {
  {"i", "j"},
  {"k", "i"},
  {"m", "k"},
  {"k", "l"},
  {"o", "n"}
};

undirectedPath(edges4, "i", "o"); // -> 0 (false)

std::vector<std::tuple<std::string, std::string>> edges5 {
  {"b", "a"},
  {"c", "a"},
  {"b", "c"},
  {"q", "r"},
  {"q", "s"},
  {"q", "u"},
  {"q", "t"}
};


undirectedPath(edges5, "a", "b"); // -> 1 (true)

std::vector<std::tuple<std::string, std::string>> edges6 {
  {"b", "a"},
  {"c", "a"},
  {"b", "c"},
  {"q", "r"},
  {"q", "s"},
  {"q", "u"},
  {"q", "t"}
};

undirectedPath(edges6, "a", "c"); // -> 1 (true)

std::vector<std::tuple<std::string, std::string>> edges7 {
  {"b", "a"},
  {"c", "a"},
  {"b", "c"},
  {"q", "r"},
  {"q", "s"},
  {"q", "u"},
  {"q", "t"}
};

undirectedPath(edges7, "r", "t"); // -> 1 (true)

std::vector<std::tuple<std::string, std::string>> edges8 {
  {"b", "a"},
  {"c", "a"},
  {"b", "c"},
  {"q", "r"},
  {"q", "s"},
  {"q", "u"},
  {"q", "t"}
};

undirectedPath(edges8, "r", "b"); // -> 0 (false)

std::vector<std::tuple<std::string, std::string>> edges9 {
  {"s", "r"},
  {"t", "q"},
  {"q", "r"}
};

undirectedPath(edges9, "r", "t"); // -> 1 (true)
}

//Complexity
    //n = number of nodes
    //e = number of edges

    //Time: O( e )
    //Space: O( n )