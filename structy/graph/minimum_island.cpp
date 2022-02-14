#include <vector>
#include <unordered_set>
#include <string>


//Write a function, minimumIsland, that takes in a grid containing Ws and Ls. W represents water and L represents Land.
//The function should return the size of the smallest island. An island is a vertically or horizontally connected region
//of land. 

//You may assume that the grid contains at least one island.

int explore(std::vector<std::vector<char>> grid, int r, int c, std::unordered_set<std::string> visited) {
    bool rowInbounds = 0 <= r && r < grid.size();
    bool colInbounds = 0 <= c && c < grid.size();
    if(!rowInbounds || !colInbounds){
        return 0;
    }
    if(grid[r][c] == 'W'){
        return 0;
    }
    std::string pos = std::to_string(r) + "," + std::to_string(c);
    if(visited.count(pos) > 0){
        return 0;
    }
    visited.insert(pos);

}

int minimumIsland(std::vector<std::vector<char>> grid) {
  std::unordered_set<std::string> visited;
  for(int r = 0; r < grid.size() ; r+=1){
      for(int c = 0; c < grid[r].size(); c+=1){
          explore(grid, r, c, visited);
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