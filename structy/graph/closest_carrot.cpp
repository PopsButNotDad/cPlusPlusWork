#include <vector>
#include <queue>
#include <unordered_set>
#include <tuple>
#include <string>

//Write a function, closestCarrot, that takes in a grid, a starting row, and a starting column. In the grid, 'X's are walls
//'O's are open spaces, and 'C's are carrots. The function should return a number representing the length of the shortest
//path from the starting position to a carrot. You may move up, down, left, or right, but cannot pass through walls (X).
//If there is no possible path to a carrot, then return -1.

//function takes grid, starter ints as arguments
int closestCarrot(std::vector<std::vector<char>> grid, int startRow, int startCol) {
    //set up the visited set to prevent cycles
    std::unordered_set<std::string> visited;
    //set up the queue as a tuple that contains three int values. 
    std::queue<std::tuple<int, int, int>> queue;
    //those three values being the row, col, and distance
    queue.push(std::tuple<int,int,int> { startRow, startCol, 0 });
    //insert the string version of the row col into the visited set
    visited.insert(std::to_string(startRow) + "," + std::to_string(startCol));
    //while the queue is not empty
    while(!queue.empty()){
        //set row, col, distance variables to whats in the front of the queue
        auto [row, col, distance] = queue.front();
        //pop the front of the queue
        queue.pop();
        //if the grid at that row column position is equal to a C then return the distance;
        if(grid[row][col] == 'C'){
            return distance;
        }
        //vector of tuples called deltas initialized to walk through the grid
        std::vector<std::tuple<int, int>> deltas { {1,0}, {-1,0}, {0,1}, {0,-1} };
        //for the tuples in the vector
        for(auto delta : deltas){
            //set destinationRow and destinationCol variables to the inner values of the tuples
            auto [dRow, dCol] = delta;
            //add those into the row and column
            int neighborRow = row + dRow;
            int neighborCol = col + dCol;
            //set up the variables to check if the new value is in bounds of the grid
            bool rowInbounds = 0 <= neighborRow && neighborRow < grid.size();
            bool colInbounds = 0 <= neighborCol && neighborCol < grid[0].size();
            //set a string position variable to the row and col
            std::string pos = std::to_string(neighborRow) + "," + std::to_string(neighborCol);
            //if the row and column are in bounds and the new position is not a wall and the position hasn't been
            //visited before
            if(rowInbounds && colInbounds && grid[neighborRow][neighborCol] != 'X' && visited.count(pos) == 0){
                //push a new tuple into the queue containing the neighboring coordinates and the distance increased by 1
                queue.push(std::tuple<int,int,int> { neighborRow, neighborCol, distance + 1 });
                //insert the position into the visited set
                visited.insert(pos);
            }
        }
    }

    

    //if no paths to the carrot are found return -1
    return -1;
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