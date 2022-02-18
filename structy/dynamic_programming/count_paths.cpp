#include <vector>
#include <unordered_map>
#include <string>

//Write a function, countPaths, that takes in a grid as an argument. In the grid, 'X' represents walls and 'O' represents
//open spaces. You may only move down or to the right and cannot pass through walls. The function should return the number
//of ways possible to travel from the top-left corner of the grid to the bottom-right corner.


int countPaths(std::vector<std::vector<char>> grid, int r, int c, std::unordered_map<std::string, int> &memo) {
    std::string pos = std::to_string(r) + "," + std::to_string(c);

    if(memo.count(pos) > 0){
        return memo[pos];
    }

    bool rInbounds = 0 <= r && r < grid.size();
    bool cInbounds = 0 <= c && c < grid[0].size();

    if(!rInbounds || !cInbounds || grid[r][c] == 'X') {
        return 0;
    }

    if(r == grid.size() - 1 && c == grid[0].size() - 1){
        return 1;
    }

   memo[pos] = countPaths(grid, r+1, c, memo) + countPaths(grid, r, c+1, memo);
   return memo[pos];
}

int countPaths(std::vector<std::vector<char>> grid) {
    std::unordered_map<std::string, int> memo;
    
    return countPaths(grid, 0, 0, memo);
}

int main() {
    std::vector<std::vector<char>> grid {
        {'O', 'O'},
        {'O', 'O'}
    };
    countPaths(grid); // -> 2

    std::vector<std::vector<char>> grid1 {
        {'O', 'O', 'X'},
        {'O', 'O', 'O'},
        {'O', 'O', 'O'}
    };
    countPaths(grid1); // -> 5

    std::vector<std::vector<char>> grid2 {
        {'O', 'O', 'O'},
        {'O', 'O', 'X'},
        {'O', 'O', 'O'}
    };
    countPaths(grid2); // -> 3

    std::vector<std::vector<char>> grid3 {
        {'O', 'O', 'O'},
        {'O', 'X', 'X'},
        {'O', 'O', 'O'}
    };
    countPaths(grid3); // -> 1

    std::vector<std::vector<char>> grid4 {
        {'O', 'O', 'X', 'O', 'O', 'O'},
        {'O', 'O', 'X', 'O', 'O', 'O'},
        {'X', 'O', 'X', 'O', 'O', 'O'},
        {'X', 'X', 'X', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O'}
    };
    countPaths(grid4); // -> 0

    std::vector<std::vector<char>> grid5 {
        {'O', 'O', 'X', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'X'},
        {'X', 'O', 'O', 'O', 'O', 'O'},
        {'X', 'X', 'X', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O'}
    };
    countPaths(grid5); // -> 42

    std::vector<std::vector<char>> grid6 {
        {'O', 'O', 'X', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'X'},
        {'X', 'O', 'O', 'O', 'O', 'O'},
        {'X', 'X', 'X', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'X'}
    };
    countPaths(grid6); // -> 0

    std::vector<std::vector<char>> grid7 {
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'}
    };
    countPaths(grid7); // -> 40116600

    std::vector<std::vector<char>> grid8 {
        {'O', 'O', 'X', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'X', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'X', 'X', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O'}
    };
    countPaths(grid8); // -> 3190434
}

//Complexity
    //r = number of rows
    //c = number of columns

    //Time: O( r*c )
    //Space: O( r*c )