// Last updated: 2/19/2026, 1:34:35 PM
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> current = {0, 0, 0};
    for (int i = 0; i < triplets.size(); i++){
        if(triplets[i][0] == target[0]){
            if(triplets[i][1] <= target[1] && triplets[i][2] <= target[2]){
                current[0]=target[0];
                current[1] = max(current[1], triplets[i][1]);
                current[2] = max(current[2], triplets[i][2]);
                if (current == target){
                    return true;
                }
            }
            
        }

        if(triplets[i][1] == target[1]){
            if(triplets[i][0] <= target[0] && triplets[i][2] <= target[2]){
                current[1]=target[1];
                current[0] = max(current[0], triplets[i][0]);
                current[2] = max(current[2], triplets[i][2]);
                if (current == target){
                    return true;
                }
            }
            
        }

        if(triplets[i][2] == target[2]){
            if(triplets[i][1] <= target[1] && triplets[i][0] <= target[0]){
                current[2]=target[2];
                current[1] = max(current[1], triplets[i][1]);
                current[0] = max(current[0], triplets[i][0]);
                if (current == target){
                    return true;
                }
            }
            
        }

        
    }    
    return false;
    }
};