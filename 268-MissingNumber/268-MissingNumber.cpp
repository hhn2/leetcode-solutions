class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        std::set<int> mySet;
        for (int i = 0; i <= n; ++i) {
        mySet.insert(i);
    }
        for (int i = 0; i < n; i++ ){
            mySet.erase(nums[i]);
        }

        return *mySet.begin();

    }
};