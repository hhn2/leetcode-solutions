// Last updated: 11/8/2025, 4:09:10 PM
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; 
        double cycles = s.length() / double(2 * numRows - 2);
        int numCycles = ceil(cycles);
        int numCols = numCycles * (numRows - 1);
         
         vector<string> myVec(numRows);

         int i = 0; // rows
         
        bool isVertical = true;
        int t = 0;
        while( t < s.length()){
            if(isVertical){
                while(i < numRows && t < s.length()){
                myVec[i]+=(s[t]);
                t++;
                i++;

                }
                isVertical = false;
                i -= 2;
            }
            else{
                for (int q = 0; q < numRows - 2 && t < s.length(); q++){
                    myVec[i]+=(s[t]);
                    t++;
                    i--;
                }
                isVertical = true;
            }

        }

            string toReturn;
        for (int n = 0; n < numRows; n++){
            toReturn += myVec[n];
        }

        return toReturn;
    }
};