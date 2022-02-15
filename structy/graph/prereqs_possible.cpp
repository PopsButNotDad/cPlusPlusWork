#include <vector>
#include <tuple>

//Write a function, prereqsPossible, that takes in a number of courses (n) and prerequisites as arguments. Courses have
//ids ranging from 0 through n - 1. A single prerequisite of {A, B} means that course A must be taken before course B.
//The function should return a boolean indicating whether or not it is possible to complete all courses.


bool prereqsPossible(int numCourses, std::vector<std::tuple<int, int>> prereqs) {
  // todo
  return;
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
    //
    //

    //Time: 
    //Space: 