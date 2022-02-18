#include <vector>
#include <string>
#include <unordered_map>

//Write a function, maxPathSum, that takes in a grid as an argument. The function should return the maximum sum 
//possible by traveling a path from the top-left corner to the bottom-right corner. You may only travel through the grid
//by moving down or right. 

//You can assume that all numbers are non-negative.

int maxPathSum(std::vector<std::vector<int>> grid) {
    // todo
    return;
}

int main() {
std::vector<std::vector<int>> grid {
  {1, 3, 12},
  {5, 1, 1},
  {3, 6, 1}
};
maxPathSum(grid); // -> 18

    std::vector<std::vector<int>> grid1 {
        {1, 2, 8, 1},
        {3, 1, 12, 10},
        {4, 0, 6, 3}
    };
    maxPathSum(grid1); // -> 36

    std::vector<std::vector<int>> grid2 {
        {1, 2, 8, 1},
        {3, 10, 12, 10},
        {4, 0, 6, 3}
    };
    maxPathSum(grid2); // -> 39

    std::vector<std::vector<int>> grid3 {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    maxPathSum(grid3); // -> 27

    std::vector<std::vector<int>> grid4 {
    {1, 1, 3, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 2, 1, 1, 6, 1, 1, 5, 1, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 5, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {2, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1},
    {2, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    maxPathSum(grid4); // -> 56
}

//Complexity
    //
    //

    //Time: 
    //Space: