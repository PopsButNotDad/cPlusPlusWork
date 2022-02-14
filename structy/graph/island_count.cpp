#include <vector>

//Write a function, islandCount, that takes in a grid containing Ws and Ls. W represents water and L represents Land. The
//function should return the number of islands on the grid. An island is a vertically or horizontally connected region of
//land.

int islandCount(std::vector<std::vector<char>> grid) {
  // todo
  return;
}

int main() {
    std::vector<std::vector<char>> grid {
        {'W', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'L', 'W'},
        {'W', 'W', 'L', 'L', 'W'},
        {'L', 'W', 'W', 'L', 'L'},
        {'L', 'L', 'W', 'W', 'W'}
    };
    islandCount(grid); // -> 3

    std::vector<std::vector<char>> grid1 {
        {'L', 'W', 'W', 'L', 'W'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'L', 'W', 'L', 'W'},
        {'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'L', 'L', 'L'}
    };
    islandCount(grid1); // -> 4

    std::vector<std::vector<char>> grid2 {
        {'L', 'L', 'L'},
        {'L', 'L', 'L'},
        {'L', 'L', 'L'}
    };
    islandCount(grid2); // -> 1

    std::vector<std::vector<char>> grid3 {
        {'W', 'W'},
        {'W', 'W'},
        {'W', 'W'}
    };
    islandCount(grid3); // -> 0
}

//Complexity:
    //r = number of rows
    //c = number of columns

    //Time: O( rc )
    //Space: O( rc )