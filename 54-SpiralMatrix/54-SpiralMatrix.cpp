// Last updated: 5/17/2025, 3:49:00 PM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int lbound = 0;
        int rbound = matrix[0].size() - 1;
        int dbound = matrix.size() - 1;
        int ubound = 1;

        vector<int> res;

        int previ = 0;
        int prevj = -1;
        int nexti = 0;
        int nextj = 0;

        while (res.size() < m * n){
            res.push_back(matrix[nexti][nextj]);


            // from 3 to 6
                if ((nextj == rbound) && (previ == nexti) && (prevj < nextj)){
                    rbound -= 1;
                    prevj = nextj;

                    nexti++;
                }
                //from 9 to 8
                else if ((nexti == dbound) && (prevj == nextj) && (previ < nexti)){
                    dbound-= 1;
                    previ = nexti;

                    nextj--;
                }
                //from 7 to 4
                else if((nextj == lbound) && (previ == nexti) && (prevj > nextj)){
                    lbound += 1;
                    prevj =nextj;

                    nexti--;
                }
                //from 4 to 5
                else if ((nexti == ubound) && (prevj == nextj) && (previ > nexti)){
                    ubound +=1;
                    previ= nexti;

                    nextj++;
                }
                else if((prevj < nextj)){
                    prevj = nextj;
                    nextj++;

                }
                else if ((previ < nexti)){
                    previ = nexti;
                    nexti++;
                }
                else if (prevj > nextj){
                    prevj = nextj;
                    nextj--;
                }
                else if (previ > nexti){
                    previ = nexti;
                    nexti--;
                }

        }
        return res;
    }
};