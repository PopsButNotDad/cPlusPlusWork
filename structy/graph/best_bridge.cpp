#include <vector>

//Write a function, bestBridge, that takes in a grid as an argument. The grid contains water (W) and land (L).
//There are exactly two islands in the grid. An Island is a vertically or horizontally connected region of lang. Return
//the minimum length bridge needed to connect the two islands. A bridge does not need to form a straight line.

int bestBridge(std::vector<std::vector<char>> grid) {
    // todo
    return;
}

int main() {
    std::vector<std::vector<char>> grid {
        {'W', 'W', 'W', 'L', 'L'},
        {'L', 'L', 'W', 'W', 'L'},
        {'L', 'L', 'L', 'W', 'L'},
        {'W', 'L', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W'}
    };
    bestBridge(grid); // -> 1

    std::vector<std::vector<char>> grid {
        {'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'L', 'W', 'W', 'L'},
        {'W', 'L', 'W', 'W', 'L'},
        {'W', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'}
    };
    bestBridge(grid); // -> 2

    std::vector<std::vector<char>> grid {
        {'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'L', 'W'},
        {'L', 'W', 'W', 'W', 'W'}
    };
    bestBridge(grid); // -> 3

    std::vector<std::vector<char>> grid {
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'L', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'L', 'L', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'L', 'L', 'L', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'L', 'L', 'L'},
        {'L', 'W', 'W', 'W', 'W', 'L', 'L', 'L'},
        {'L', 'L', 'L', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}
    };

    std::vector<std::vector<char>> grid {
        {'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L'},
        {'L', 'W', 'W', 'W', 'W', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'W', 'W', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'W', 'W', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'W', 'W', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'W', 'W', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'L', 'W', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'W', 'W', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'W', 'W', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'W', 'W', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'W', 'W', 'W', 'W', 'L'},
        {'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L'}
    };
    bestBridge(grid); // -> 2

    std::vector<std::vector<char>> grid {
        {'W', 'L', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'L', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'L'}
    };
    bestBridge(grid); // -> 8
}

//Complexity
    //r = number of rows
    //c = number of colummns

    //Time: O( rc )
    //Space: O( rc )