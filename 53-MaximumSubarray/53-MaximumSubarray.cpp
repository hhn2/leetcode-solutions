// Last updated: 6/15/2025, 9:10:48 PM
class Solution {
public:

   int fixedi(vector<int>& nums, int l, int r) {
    int maxx = INT_MIN, curr = 0;
    for (int i = l; i <= r; ++i) {
        curr += nums[i];
        maxx = max(maxx, curr);
    }
    return maxx;
}

int fixedj(vector<int>& nums, int l, int r) {
    int maxx = INT_MIN, curr = 0;
    for (int i = r; i >= l; --i) {
        curr += nums[i];
        maxx = max(maxx, curr);
    }
    return maxx;
}

int helper(vector<int>& nums, int l, int r) {
    if (l == r) return nums[l];
    int mid = (l + r) / 2;
    int s1 = helper(nums, l, mid);
    int s2 = helper(nums, mid + 1, r);
    int s3 = fixedj(nums, l, mid) + fixedi(nums, mid + 1, r);
    return max({s1, s2, s3});
}

int maxSubArray(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
}

};