#include <vector>
#include <unordered_set>
#include <string>
#include <tuple>
#include <queue>

//Write a function, bestBridge, that takes in a grid as an argument. The grid contains water (W) and land (L).
//There are exactly two islands in the grid. An Island is a vertically or horizontally connected region of lang. Return
//the minimum length bridge needed to connect the two islands. A bridge does not need to form a straight line.

//function that takes the current position at row, column and turns it into string for later use
std::string stringifyPos(int r, int c){
    return std::to_string(r) + "," + std::to_string(c);
}

//function that checks if the current position is inbounds and returns boolean
bool isInbounds(std::vector<std::vector<char>> grid, int r, int c){
    bool rInbounds = 0 <= r && r < grid.size();
    bool cInbounds = 0 <= c && c < grid[0].size();

    return rInbounds && cInbounds;
}

//recursive depth first traversal to find an initial island
//takes in grid, reference to visited set, reference to the land positions, row, and column
void exploreIsland(std::vector<std::vector<char>> grid,std::unordered_set<std::string> &visited,
  std::vector<std::tuple<int, int>> &landPositons, int r, int c) {
        //set position variable to string of row column using stringify function above
        std::string pos = stringifyPos(r, c);
        //if current positions is not inbounds, or is water, or has been visited before
        if(!isInbounds(grid, r, c) || grid[r][c] == 'W' || visited.count(pos) > 0){
            //then return
            return;
        }
        //inser the current position into the visited set
        visited.insert(pos);
        //push back the position of the land at that row column
        landPositons.push_back(std::tuple<int, int> {r, c});

        //explore the grid 
        exploreIsland(grid, visited, landPositons, r - 1, c);
        exploreIsland(grid, visited, landPositons, r + 1, c);
        exploreIsland(grid, visited, landPositons, r, c - 1);
        exploreIsland(grid, visited, landPositons, r, c + 1);

}

//best bridge function takes in grid as argument
int bestBridge(std::vector<std::vector<char>> grid) {
    //create the first visited set
    std::unordered_set<std::string> visited;
    //create a vector of tuples to show where an island is
    std::vector<std::tuple<int, int>> mainIsland;
    //iterate through the grid
    for(int r = 0; r < grid.size(); r+=1){
        for(int c = 0; c < grid[0].size(); c+=1){
            //create vector of tuples indicated where land is
            std::vector<std::tuple<int, int>> landPositions;
            //explore the island to get all the positions of the land using the recursive function above
            exploreIsland(grid, visited, landPositions, r, c);
            //if the land has been seen before 
            if(landPositions.size() > 0){
                //set the main island to the current positions of that land
                mainIsland = landPositions;
            }
        }
    }
    //initialize the queue for BFS
    std::queue<std::tuple<int, int, int>> queue;
    //initialize the second visited set
    std::unordered_set<std::string> visited2;
    //for all the land mass positions inside the mainIsland variable
    for(auto [r, c] : mainIsland){
        //push those positons into the queue and then set their distance to -1 (to account for off by 1)
        queue.push(std::tuple<int, int, int> { r, c, -1 });
        //also insert those positions into the second visited set
        visited2.insert(stringifyPos(r, c));
    }
    //iterate through the queue while it is not empty
    while(!queue.empty()){
        //create row, col, and distance variables based on the tuple inside the queue (sort of like the current)
        auto [row, col, dist] = queue.front();
        //remove them once looked at
        queue.pop();
        //if the grid at the explored positions land and it isnt a part of the main island
        if (grid[row][col] == 'L' && dist != -1){
            //then return the distance
            return dist;
        }
        //create vector of tuples containing the ways to explore the grid
        std::vector<std::tuple<int, int>> deltas { {1,0}, {-1,0}, {0,1}, {0,-1} };
        //for all the ways to explore the grid
        for(auto [dRow, dCol] : deltas){
            //set the neighbor values to the current row/col plus the way to explore
            int neighborRow = row + dRow;
            int neighborCol = col + dCol;
            //create string of the neighboring position using the function above and the neighboring row column values
            std::string neighborPos = stringifyPos(neighborRow, neighborCol);
            //if these new neighbors are inbounds and have not been visited
            if(isInbounds(grid, neighborRow, neighborCol) && visited2.count(neighborPos) == 0){
                //insert the position into the second visited set
                visited2.insert(neighborPos);
                //then push them into the queue
                queue.push(std::tuple<int, int, int> {neighborRow, neighborCol, dist+1});
            }
        }
    }

    return -1;

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

    std::vector<std::vector<char>> grid1 {
        {'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'L', 'W', 'W', 'L'},
        {'W', 'L', 'W', 'W', 'L'},
        {'W', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'}
    };
    bestBridge(grid1); // -> 2

    std::vector<std::vector<char>> grid2 {
        {'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'L', 'W'},
        {'L', 'W', 'W', 'W', 'W'}
    };
    bestBridge(grid2); // -> 3

    std::vector<std::vector<char>> grid3 {
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
    bestBridge(grid3);

    std::vector<std::vector<char>> grid4 {
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
    bestBridge(grid4); // -> 2

    std::vector<std::vector<char>> grid5 {
        {'W', 'L', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'L', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'L'}
    };
    bestBridge(grid5); // -> 8
}

//Complexity
    //r = number of rows
    //c = number of colummns

    //Time: O( rc )
    //Space: O( rc )