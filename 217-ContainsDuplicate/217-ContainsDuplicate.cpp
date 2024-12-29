class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> myMap;
        for (auto it = nums.begin(); it != nums.end();it++){
            if (myMap[*it] != 0){
                return true;
            }
            myMap[*it]++;

        }

        return false;
    }
};