// Last updated: 7/2/2026, 11:17:51 PM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                 
                int x = mid - 1;
                int y = mid + 1;
                while( x >= 0 && nums[x] == target){
                    x -= 1;
                }
                while (y <= nums.size()-1 && nums[y] == target){
                    y += 1;
                }

                
                return {x + 1,y - 1};
            }

            else if (nums[mid] > target){
                right = mid - 1;

            }

            else if (nums[mid] < target){
                left = mid + 1;
            }
        }
        return {-1, -1};
    }
};