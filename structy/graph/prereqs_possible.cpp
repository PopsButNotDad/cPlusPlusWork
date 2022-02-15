#include <vector>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

//Write a function, prereqsPossible, that takes in a number of courses (n) and prerequisites as arguments. Courses have
//ids ranging from 0 through n - 1. A single prerequisite of {A, B} means that course A must be taken before course B.
//The function should return a boolean indicating whether or not it is possible to complete all courses.


std::unordered_map<int, std::vector<int>> makeGraph(std::vector<std::tuple<int, int>> edges){
    std::unordered_map<int, std::vector<int>> graph;

    for(auto[a, b] : edges){
        graph[a].push_back(b);
    }

    return graph;
}

bool hasCycle(std::unordered_map<int, std::vector<int>> graph, int node, std::unordered_set<int> &visiting, 
  std::unordered_set<int> &visited){
    if(visiting.count(node) > 0){
        return true;
    }

    if(visited.count(node) > 0){
        return false;
    }

    visiting.insert(node);

    for(int neighbor : graph[node]){
        if(hasCycle(graph, neighbor, visiting, visited)){
            return true;
        }
    }

    visiting.erase(node);
    visited.insert(node);

    return false;
}

bool prereqsPossible(int numCourses, std::vector<std::tuple<int, int>> prereqs) {
    std::unordered_map<int, std::vector<int>> graph = makeGraph(prereqs);
    std::unordered_set<int> visiting;
    std::unordered_set<int> visited;

    for (int node = 0; node < numCourses; node +=1){
        if(hasCycle(graph, node, visiting, visited)){
            return false;
        }
    }

    return true;
}

int main() {
    int numCourses = 6;
    std::vector<std::tuple<int, int>> prereqs {
        {0, 1},
        {2, 3},
        {0, 2},
        {1, 3},
        {4, 5}
    };
    prereqsPossible(numCourses, prereqs); // -> 1 (true)

    int numCourses1 = 6;
    std::vector<std::tuple<int, int>> prereqs1 {
        {0, 1},
        {2, 3},
        {0, 2},
        {1, 3},
        {4, 5},
        {3, 0}
    };
    prereqsPossible(numCourses1, prereqs1); // -> 0 (false)

    int numCourses2 = 5;
    std::vector<std::tuple<int, int>> prereqs2 {
        {2, 4},
        {1, 0},
        {0, 2},
        {0, 4}
    };
    prereqsPossible(numCourses2, prereqs2); // -> 1 (true)

    int numCourses3 = 6;
    std::vector<std::tuple<int, int>> prereqs3 {
        {2, 4},
        {1, 0},
        {0, 2},
        {0, 4},
        {5, 3},
        {3, 5}
    };
    prereqsPossible(numCourses3, prereqs3); // -> 0 (false)

    int numCourses4 = 8;
    std::vector<std::tuple<int, int>> prereqs4 {
        {1, 0},
        {0, 6},
        {2, 0},
        {0, 5},
        {3, 7},
        {4, 3}
    };
    prereqsPossible(numCourses4, prereqs4); // -> 1 (true)

    int numCourses5 = 8;
    std::vector<std::tuple<int, int>> prereqs5 {
        {1, 0},
        {0, 6},
        {2, 0},
        {0, 5},
        {3, 7},
        {7, 4},
        {4, 3}
    };
    prereqsPossible(numCourses5, prereqs5); // -> 0 (false)

    int numCourses6 = 42;
    std::vector<std::tuple<int, int>> prereqs6 {{6, 36}};
    prereqsPossible(numCourses6, prereqs6); // -> 1 (true)
}

//Complexity
    //n = number of courses
    //p = number of prereqs

    //Time: O( n+p )
    //Space: O( n+p )