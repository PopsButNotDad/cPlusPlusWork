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


int semestersRequired(int numCourses, std::vector<std::tuple<int, int>> prereqs) {
    // todo
    return;
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