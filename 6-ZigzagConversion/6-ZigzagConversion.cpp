// Last updated: 11/8/2025, 3:22:15 PM
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; 
        double cycles = s.length() / double(2 * numRows - 2);
        int numCycles = ceil(cycles);
        int numCols = numCycles * (numRows - 1);

        vector<vector<char>> my2DVector(numRows, vector<char>(numCols, ' '));

        bool isFullCol = true;

        int i = 0;  // col
        int j = 0;  //row
        int t = 0;

        while ( t < s.length()  ){
            if (isFullCol){
                while ( j < numRows && t < s.length()){
                my2DVector[j][i] = s[t];
                t++;
                j++;
                }
                i++;
                isFullCol = false;
                j -= 2;
                

            }
            
            else{for (int w = 0; w < numRows - 2 && t < s.length(); w++){
                
                my2DVector[j][i] = s[t];
                t++;
                i++;
                j--;
            }
            isFullCol = true;
            }
        
            

        }

        string toReturn;
        for (int q = 0; q < numRows; q++){
            for (int r = 0;  r < numCols; r++){
            if( my2DVector[q][r] != ' '){
                toReturn +=  my2DVector[q][r];
            }
            }
        }
        return toReturn;
    }
};