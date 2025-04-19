// Last updated: 4/19/2025, 5:27:11 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0);  // Use 32 bits to include sign bit
        
        // Count bits at each position
        for (int num : nums) {
            // Process all 32 bits including sign bit
            for (int i = 0; i < 32; i++) {
                bits[i] += (num >> i) & 1;
                bits[i] %= 3;
            }
        }
        
        // Reconstruct the number
        int result = 0;
        for (int i = 0; i < 32; i++) {
            result |= (bits[i] << i);
        }
        
        return result;
    }
};