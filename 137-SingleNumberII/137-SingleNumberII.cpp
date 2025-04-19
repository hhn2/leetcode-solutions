// Last updated: 4/19/2025, 5:27:51 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0);
        
        // Count bits at each position
        for (int num : nums) {
            for (int i = 0; i < 32; i++) {
                bits[i] += (num >> i) & 1;
                if (bits[i] == 3) bits[i] = 0; // Replace modulo with conditional
            }
        }
        
        int result = 0;
        for (int i = 0; i < 32; i++) {
            result |= (bits[i] << i);
        }
        
        return result;
    }
};