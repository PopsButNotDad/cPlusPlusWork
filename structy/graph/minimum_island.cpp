#include <vector>


//Write a function, minimumIsland, that takes in a grid containing Ws and Ls. W represents water and L represents Land.
//The function should return the size of the smallest island. An island is a vertically or horizontally connected region
//of land. 

//You may assume that the grid contains at least one island.


int minimumIsland(std::vector<std::vector<char>> grid) {
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
    minimumIsland(grid); // -> 2

    std::vector<std::vector<char>> grid {
        {'L', 'W', 'W', 'L', 'W'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'L', 'W', 'L', 'W'},
        {'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'L', 'L', 'L'}
    };
    minimumIsland(grid); // -> 1

    std::vector<std::vector<char>> grid {
        {'L', 'L', 'L'},
        {'L', 'L', 'L'},
        {'L', 'L', 'L'}
    };
    minimumIsland(grid); // -> 9

    std::vector<std::vector<char>> grid {
        {'W', 'W'},
        {'L', 'L'},
        {'W', 'W'},
        {'W', 'L'}
    };
    minimumIsland(grid); // -> 1


}

//Complexity
    //r = number of rows
    //c = number of columns

    //Time: O( rc )
    //Space: O( rc )