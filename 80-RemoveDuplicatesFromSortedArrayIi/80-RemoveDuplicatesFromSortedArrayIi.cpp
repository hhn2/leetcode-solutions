// Last updated: 7/2/2026, 11:17:36 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1){
            return 1;
        }
        int prev = nums[0];
        int count = 1;
        int pos = 1;
        for (int i = 1; i  < nums.size(); i++){

            if(prev == nums[i] && count == 2){
                continue;
            }
            else if (prev==nums[i]){
                count++;
                nums[pos] = nums[i];
                pos++;
            }
            else{
                count = 1;
                prev = nums[i];
                nums[pos] = nums[i];
                pos++;

            }
        }

        return pos;

        
    }


};