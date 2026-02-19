// Last updated: 2/19/2026, 1:35:10 PM
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        if (nums.size() == 1 || nums.size() == 2){
            return false;
        }


        
        int first = INT_MAX;
        int second = INT_MAX;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > second){
                return true;
            }
              
            else if (nums[i] <= first){
                first = nums[i];
            }
          else {
                second = nums[i];
            }
          
        }
    return false;

    }
};

