#include <vector>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

//Write a function, semestersRequired, that takes in a number of courses (n) and a list of prerequisites as arguments.
//Courses have ids ranings from 0 through n - 1. A single prerequisite of {A, B} means that course A must be taken before
//course B. Return the minimum number of semesters required to complete all n courses. There is no limit on how many courses
//you can take in a single semester, as long as the prerequisites of a course are satisfied before taking it.

//Note that given {A, B}, you cannot take course A and course B concurrently in the same semester. You must take A in some
//semester before B. 

//You can assume that it is possible to eventually complete all courses.

//function to create map from edge list, takes in the prereqs/edges vector as an argument
std::unordered_map<int, std::vector<int>> buildGraph(std::vector<std::tuple<int, int>> edges){
    //create the adjacency list
    std::unordered_map<int, std::vector<int>> graph;
    //for the edge values in the edges list
    for (auto[a, b] : edges){
        //push the second value into the graph at the first value
        graph[a].push_back(b);
    }
    //return the graph
    return graph;
}

//recursive helper function takes in the graph, reference to distance map, and an int node
int exploreDistance(std::unordered_map<int, std::vector<int>> graph, std::unordered_map<int, int> &distanceMap, int node){
    //if the node value is already in the distance map
    if(distanceMap.count(node) > 0){
        //return the distance map value at that node
        return distanceMap[node];
    }
    //max value variable
    int longest = 0;
    //for all the neighbors in the graph at that node value
    for(int neighbor : graph[node]){
        //explore the neighbors and save it to a variable neighborDistance
        int neighborDistance = exploreDistance(graph, distanceMap, neighbor);
        //if neighborDistance is larger than the max variable
        if(neighborDistance > longest){
            //set max variable to the neighborDistance
            longest = neighborDistance;
        }
    }
    //the distance map at that node is equal to the max variable plus 1 (include the self)
    distanceMap[node] = longest + 1;
    //return the value within the distance map at that node
    return distanceMap[node];

}
//semesters required function takes in the list of courses along with the edges (prereqs)
int semestersRequired(int numCourses, std::vector<std::tuple<int, int>> prereqs) {
    //create adjacency list using function above and call it graph
    std::unordered_map<int, std::vector<int>> graph = buildGraph(prereqs);
    //create the distance map
    std::unordered_map<int, int> distanceMap;
    //for loop iterating through all the courses
    for (int node = 0; node < numCourses; node +=1){
        //if the node has no nexts
        if(graph[node].size() == 0){
            //populate the map at that node with 1 (include the self)
            distanceMap[node] = 1;
        }
    }
    //max value variable
    int longest = 0;
    //once again iterate through all the courses
    for (int node = 0; node < numCourses; node +=1){
        //set distance variable equal to the helper function ran at that node (recursive leap of faith)
        int distance = exploreDistance(graph, distanceMap, node); //Todo
        //if the distance returned is longer than the max variable 
        if(distance > longest){
            //set the max variable to that distance
            longest = distance;
        }
    }
    //return the max variable
    return longest;
}

int main() {
    int numCourses = 6;
    std::vector<std::tuple<int, int>> prereqs {
        {1, 2},
        {2, 4},
        {3, 5},
        {0, 5}
    };
    semestersRequired(numCourses, prereqs); // -> 3

    int numCourses1 = 7;
    std::vector<std::tuple<int, int>> prereqs1 {
        {4, 3},
        {3, 2},
        {2, 1},
        {1, 0},
        {5, 2},
        {5, 6}
        };
    semestersRequired(numCourses1, prereqs1); // -> 5

    int numCourses2 = 5;
    std::vector<std::tuple<int, int>> prereqs2 {
        {1, 0},
        {3, 4},
        {1, 2},
        {3, 2}
    };
    semestersRequired(numCourses2, prereqs2); // -> 2

    int numCourses3 = 12;
    std::vector<std::tuple<int, int>> prereqs3 {};
    semestersRequired(numCourses3, prereqs3); // -> 1

    int numCourses4 = 3;
    std::vector<std::tuple<int, int>> prereqs4 {
        {0, 2},
        {0, 1},
        {1, 2}
    };
    semestersRequired(numCourses4, prereqs4); // -> 3

    int numCourses5 = 6;
    std::vector<std::tuple<int, int>> prereqs5 {
        {3, 4},
        {3, 0},
        {3, 1},
        {3, 2},
        {3, 5}
    };
    semestersRequired(numCourses5, prereqs5); // -> 2
}

//Complexity
    //n = number of courses
    //p = number of prereqs

    //Time: O( p )
    //Space: O( n )