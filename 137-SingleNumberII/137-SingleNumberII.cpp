// Last updated: 4/19/2025, 5:29:10 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0);  
        
        for (int num : nums) {
            for (int i = 0; i < 32; i++) {
                bits[i] += (num >> i) & 1;
                bits[i] %= 3;
            }
        }
        
        int result = 0;
        for (int i = 0; i < 32; i++) {
            result |= (bits[i] << i);
        }
        
        return result;
    }
};