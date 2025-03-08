class Solution {
public:
    // Simulates one minute of oranges rotting
    void oneMinute(vector<vector<int>>& grid){
        vector<vector<int>> myCopy = grid;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 2){
                    // Check top neighbor
                    if (i > 0 && myCopy[i-1][j] == 1){
                        myCopy[i-1][j] = 2;
                    }
                    // Check bottom neighbor
                    if (i + 1 < m && myCopy[i+1][j] == 1){
                        myCopy[i+1][j] = 2;
                    }
                    // Check left neighbor
                    if (j > 0 && myCopy[i][j-1] == 1){
                        myCopy[i][j-1] = 2;
                    }
                    // Check right neighbor
                    if (j + 1 < n && myCopy[i][j+1] == 1){
                        myCopy[i][j+1] = 2;
                    }
                }
            }
        }
        grid = myCopy;
    }

    // Checks if any fresh oranges remain in the grid
    bool existFresh(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    return true;
                }
            }
        }
        return false;
    }

    // Main function to determine minutes until all oranges rot or impossible
    int orangesRotting(vector<vector<int>>& grid) {
        // Check if there are any fresh oranges
        if (!existFresh(grid)) return 0;
        
        // Check if there are any rotten oranges to start with
        bool hasRotten = false;
        for (const auto& row : grid) {
            for (int cell : row) {
                if (cell == 2) {
                    hasRotten = true;
                    break;
                }
            }
            if (hasRotten) break;
        }
        // If there are fresh oranges but no rotten ones, impossible
        if (!hasRotten) return -1;
        
        int minutes = 0;
        vector<vector<int>> prevGrid;
        
        while (existFresh(grid)) {
            // Save the current state before simulating a minute
            prevGrid = grid;
            
            oneMinute(grid);
            minutes++;
            
            // If nothing changed but fresh oranges still exist,
            // it's impossible to rot all oranges
            if (prevGrid == grid) {
                return -1;
            }
        }
        
        return minutes;
    }
};