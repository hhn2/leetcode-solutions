// Last updated: 11/8/2025, 11:29:24 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }
    
private:
    int maxSubArrayHelper(vector<int>& nums, int left, int right) {
        // Base case: only one element
        if (left == right) {
            return nums[left];
        }
        
        int mid = left + (right - left) / 2;
        
        // Recursively find max in left and right halves
        int leftMax = maxSubArrayHelper(nums, left, mid);
        int rightMax = maxSubArrayHelper(nums, mid + 1, right);
        
        // Find max subarray crossing the middle
        int crossMax = maxCrossingSum(nums, left, mid, right);
        
        // Return the maximum of the three
        return max({leftMax, rightMax, crossMax});
    }
    
    int maxCrossingSum(vector<int>& nums, int left, int mid, int right) {
        // Find max sum starting from mid and going left
        int leftSum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }
        
        // Find max sum starting from mid+1 and going right
        int rightSum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        
        // Return sum of both sides
        return leftSum + rightSum;
    }
};