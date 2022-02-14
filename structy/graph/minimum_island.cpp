#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>


//Write a function, minimumIsland, that takes in a grid containing Ws and Ls. W represents water and L represents Land.
//The function should return the size of the smallest island. An island is a vertically or horizontally connected region
//of land. 

//You may assume that the grid contains at least one island.

int explore(std::vector<std::vector<char>> grid, int r, int c, std::unordered_set<std::string> &visited) {
    bool rowInbounds = 0 <= r && r < grid.size();
    bool colInbounds = 0 <= c && c < grid[0].size();
    if(!rowInbounds || !colInbounds){
        return -1;
    }
    if(grid[r][c] == 'W'){
        return -1;
    }
    std::string pos = std::to_string(r) + "," + std::to_string(c);
    if(visited.count(pos) > 0){
        return -1;
    }
    visited.insert(pos);

    int totalSize = 1;

    totalSize += std::max(0, explore(grid, r+1, c, visited));
    totalSize += std::max(0, explore(grid, r-1, c, visited));
    totalSize += std::max(0, explore(grid, r, c+1, visited));
    totalSize += std::max(0, explore(grid, r, c-1, visited));

    return totalSize;

}

int minimumIsland(std::vector<std::vector<char>> grid) {
    int min = 0;
    std::unordered_set<std::string> visited;
    for(int r = 0; r < grid.size() ; r+=1){
        for(int c = 0; c < grid[0].size(); c+=1){
            int islandSize = explore(grid, r, c, visited);

            if(islandSize != -1 && (min == 0 || islandSize < min)){
                min = islandSize;
            }
        }
    }
    return min;
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

    std::vector<std::vector<char>> grid1 {
        {'L', 'W', 'W', 'L', 'W'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'L', 'W', 'L', 'W'},
        {'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'L', 'L', 'L'}
    };
    minimumIsland(grid1); // -> 1

    std::vector<std::vector<char>> grid2 {
        {'L', 'L', 'L'},
        {'L', 'L', 'L'},
        {'L', 'L', 'L'}
    };
    minimumIsland(grid2); // -> 9

    std::vector<std::vector<char>> grid3 {
        {'W', 'W'},
        {'L', 'L'},
        {'W', 'W'},
        {'W', 'L'}
    };
    minimumIsland(grid3); // -> 1


}

//Complexity
    //r = number of rows
    //c = number of columns

    //Time: O( rc )
    //Space: O( rc )