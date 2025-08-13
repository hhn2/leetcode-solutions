// Last updated: 8/13/2025, 6:57:18 PM
class Solution {
public:
    int climbStairs(int n) {
        vector<bool> visited (n, false );
        vector<int> answer (n, 0);
        return F(n, visited, answer);
       
    }

    int F (int n,  vector<bool>&visited, vector<int>& answer){
        if (visited[n - 1] == true){
            return answer[n-1];
        }
        if (n==1){
            return 1;
        }
        else if (n==2){
            return 2;
        }
        answer[n-1]= F(n-1, visited, answer) + F(n-2, visited, answer);
        visited[n-1] = true;
        return answer[n-1];
    }


};


