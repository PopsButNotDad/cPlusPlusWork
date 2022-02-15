#include <vector>
#include <queue>
#include <unordered_set>
#include <tuple>

//Write a function, closestCarrot, that takes in a grid, a starting row, and a starting column. In the grid, 'X's are walls
//'O's are open spaces, and 'C's are carrots. The function should return a number representing the length of the shortest
//path from the starting position to a carrot. You may move up, down, left, or right, but cannot pass through walls (X).
//If there is no possible path to a carrot, then return -1.


int closestCarrot(std::vector<std::vector<char>> grid, int startRow, int startCol) {
    std::unordered_set<std::string> visited;
    std::queue<std::tuple<std::string, int>> queue;




    return;
}

int main() {
std::vector<std::vector<char>> grid {
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'X', 'O', 'O', 'O'},
    {'O', 'X', 'X', 'O', 'O'},
    {'O', 'X', 'C', 'O', 'O'},
    {'O', 'X', 'X', 'O', 'O'},
    {'C', 'O', 'O', 'O', 'O'}
};
closestCarrot(grid, 1, 2); // -> 4

std::vector<std::vector<char>> grid {
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'X', 'O', 'O', 'O'},
    {'O', 'X', 'X', 'O', 'O'},
    {'O', 'X', 'C', 'O', 'O'},
    {'O', 'X', 'X', 'O', 'O'},
    {'C', 'O', 'O', 'O', 'O'}
};
closestCarrot(grid, 0, 0); // -> 5

std::vector<std::vector<char>> grid {
    {'O', 'O', 'X', 'X', 'X'},
    {'O', 'X', 'X', 'X', 'C'},
    {'O', 'X', 'O', 'X', 'X'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'X', 'X', 'X', 'X'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'C', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'}
};
closestCarrot(grid, 3, 4); // -> 9

std::vector<std::vector<char>> grid {
    {'O', 'O', 'X', 'O', 'O'},
    {'O', 'X', 'X', 'X', 'O'},
    {'O', 'X', 'C', 'C', 'O'},
};
closestCarrot(grid, 1, 4); // -> 2

std::vector<std::vector<char>> grid {
    {'O', 'O', 'X', 'O', 'O'},
    {'O', 'X', 'X', 'X', 'O'},
    {'O', 'X', 'C', 'C', 'O'},
};

closestCarrot(grid, 2, 0); // -> -1

std::vector<std::vector<char>> grid {
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X'},
    {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'C'},
};

closestCarrot(grid, 0, 0); // -> -1


}

//Complexity
    //r = number of rows
    //c = number of columns

    //Time: O( rc )
    //Space:O( rc )