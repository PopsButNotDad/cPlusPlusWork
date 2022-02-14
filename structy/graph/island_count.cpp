#include <vector>
#include <unordered_set>
#include <string>

//Write a function, islandCount, that takes in a grid containing Ws and Ls. W represents water and L represents Land. The
//function should return the number of islands on the grid. An island is a vertically or horizontally connected region of
//land.

bool explore(std::vector<std::vector<char>> grid, int r, int c, std::unordered_set<std::string> &visited){
    bool rowInbounds = 0 <= r && r < grid.size();
    bool colInbounds = 0 <= c && c < grid.size();


    if(!rowInbounds || !colInbounds){
        return false;
    }

    if(grid[r][c] == 'W'){
        return false;
    }

    std::string pos = std::to_string(r) + "," + std::to_string(c);

    if(visited.count(pos) > 0){
        return false;
    }

    visited.insert(pos);

    explore(grid, r+1, c, visited);
    explore(grid, r-1, c, visited);
    explore(grid, r, c+1, visited);
    explore(grid, r, c-1, visited);


    return true;
}

int islandCount(std::vector<std::vector<char>> grid) {
    std::unordered_set<std::string> visited;
    for(int r = 0; r < grid.size(); r+=1){
        for(int c = 0; c < grid[0].size(); c+=1){
            explore(grid, r, c, visited); //todo
        }
    }
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