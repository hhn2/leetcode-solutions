// Last updated: 8/13/2025, 8:20:12 PM
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp (m, vector<int>(n, -1));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
            }
        }

        return c(1, 1, m, n, dp);
    }

    int c (int i, int j, int m, int n, vector<vector<int>>& dp){
        if ((i == m) && (j == n)){
            if ((dp[i-1][j-1]!=0)){
            return 1;
            }
            else {return 0;}
        }
        if ((i > m) || (j > n)){
            return 0;
        }
        
        if(dp[i-1][j-1]!= -1){
            return dp[i-1][j-1];
        }
        else{
            int answer = c(i+1, j, m, n, dp )+ c(i, j+1, m, n, dp);
            dp[i-1][j-1] = answer;
            return answer;

        }
    }
};



// base case: c(m, n) = 1 where m is num of columns and n is the num of rows. 
// answer : c ( 1, 1)
// recursion : c (i, j) = c (i+1, j) + c(i, j+1)