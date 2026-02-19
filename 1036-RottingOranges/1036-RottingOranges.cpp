// Last updated: 2/19/2026, 1:34:45 PM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rottens;
        int minutes = 0;
        for (int x = 0; x < grid.size(); x++){
            for (int y = 0; y < grid[0].size(); y++){
                if (grid[x][y] == 2){
                    pair<int, int> p = {x, y};
                    rottens.push(p);
                }
            }
        }
        int count = rottens.size();
        while(rottens.size() != 0){
            if(count == 0){
                minutes++;
                count = rottens.size();
            }
            pair<int, int> p = rottens.front();
            rottens.pop();
            count--;
            // if the rotten orange is not a corner or edge position
            if (p.first != 0){
                
                if (grid[p.first - 1][p.second] == 1){
                    grid[p.first - 1][p.second] = 2;
                    pair<int, int> q ={p.first - 1, p.second}; 
                    rottens.push(q);
                }
            }

            if (p.first != grid.size() - 1){

                if (grid[p.first + 1][p.second] == 1){
                    grid[p.first + 1][p.second] = 2;
                    pair<int, int> q ={p.first + 1, p.second}; 
                    rottens.push(q);
                }
            }

            if(p.second != 0){

                if (grid[p.first][p.second - 1] == 1){
                    grid[p.first][p.second - 1] = 2;
                    pair<int, int> q ={p.first, p.second - 1}; 
                    rottens.push(q);
                }
            }
            if (p.second != grid[0].size() - 1){

                if (grid[p.first][p.second + 1] == 1){
                    grid[p.first][p.second + 1] = 2;
                    pair<int, int> q ={p.first, p.second + 1}; 
                    rottens.push(q);
                }
            }

            }

            //check if there are any fresh oranges left
            for (int x = 0; x < grid.size(); x++){
            for (int y = 0; y < grid[0].size(); y++){
                if (grid[x][y] == 1){
                    return -1;
                }
            }
        }

        return minutes;


            
        }
    };
