// Last updated: 8/13/2025, 7:28:17 PM
#include <algorithm>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
        return helper(0, 0, grid, memo);
    }

    int helper(int a, int b, vector<vector<int>>& grid, vector<vector<int>>& memo){
         if (a >= grid.size()){
            return INT_MAX;
        }
        if (b >= grid[0].size()){
            return INT_MAX;
        }
         if (a == grid.size()-1 && b == grid[0].size()-1){
            return grid[grid.size() - 1] [grid[0].size() - 1];
        }
        if (memo[a][b] != -1) {
            return memo[a][b];
        }
       
       
        int result = grid[a][b] + min(helper(a + 1, b, grid, memo), helper(a, b + 1, grid, memo));
memo[a][b] = result; 
return result;
    }
};

// subproblem : c(i, j) be the sum of the best path from curr position i, j to the bottom right
// answer : c(0, 0)
// to get c(i,j), we need to get the min of( grid[i,j] + c(i+1, j) and grid[i,j] + c(i, j+1)
// base cases: c(grid.size(), grid[0].size()) = grid[grid.size(), gird[0].size()];