// Last updated: 2/19/2026, 1:35:04 PM
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Count frequencies using a map
        map<int, int> myMap;
        for (int x : nums) {
            ++myMap[x];
        }

        // Store frequencies and their corresponding numbers in a vector
        vector<pair<int, int>> myVec;
        for (auto [num, freq] : myMap) {
            myVec.emplace_back(freq, num);
        }

        // Sort the vector by frequency in descending order
        sort(myVec.begin(), myVec.end(), greater<pair<int, int>>());

        // Retrieve the top-k elements
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(myVec[i].second);
        }

        return ans;
    }
};