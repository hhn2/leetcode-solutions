// Last updated: 8/13/2025, 7:58:11 PM
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m, vector<int> (n , -1));
        return c(1, 1, m, n, dp);
    }
    int c (int x, int y,int m, int n, vector<vector<int>>& dp)
{   
    if (x > m || y > n){
        return 0;
    }
      if (x == m && y == n){
        return 1;
    }
    if ((x == m - 1) && (y == n)){
        return 1;
    }
    if ((x == m )&& (y = n-1)){
        return 1;
    }

    if (dp[x-1][y-1]!= -1){
        return dp[x-1][y-1];
    }
  
    else{
        int answer = c(x+1, y, m, n, dp) + c(x, y+1, m, n, dp);
        dp[x-1][y-1] = answer;
        return answer;
    }

}    
};

// base case: c(m , n) = 0, c (m-1, n) = 1, c(m, n-1) = 1
// answer : c (1, 1)
// recursion : c(i,j) = c(i+1, j) + c(i, j+1)