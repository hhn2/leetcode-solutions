class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++){
            int toFind = target - nums[i];
            for (int j = i + 1;  j < nums.size(); j++){
                if (nums[j] == toFind){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};