// Last updated: 6/15/2025, 9:09:46 PM
class Solution {
public:
    int fixedi(vector<int>& nums){
        int maxx = nums[0];
        int currsum = nums[0];
        for (int i = 1; i < nums.size(); i ++){
            currsum += nums[i];
            if (currsum > maxx){
                maxx = currsum;
            }
        }
        return maxx;

        
    }
    int fixedj(vector<int>&nums){
        int maxx = nums[nums.size()-1];
        int currsum = nums[nums.size()-1];
        for (int i = nums.size()-2; i >= 0; i--){
            currsum += nums[i];
            if (currsum > maxx){
                maxx=currsum;
            }
        }
        return maxx;

    }
     int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0]; // fix: should return the element, not 0
        }

        int mid = nums.size() / 2;

        // split left and right subarrays
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        int s1 = maxSubArray(left);
        int s2 = maxSubArray(right);
        int s3 = fixedj(left) + fixedi(right);

        return max({s1, s2, s3});
    }
};