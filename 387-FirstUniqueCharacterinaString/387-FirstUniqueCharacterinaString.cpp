class Solution {
public:
    int firstUniqChar(std::string s) {
        // Step 1: Count the frequency of each character
        std::unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }

        // Step 2: Find the first character with a count of 1
        for (int i = 0; i < s.length(); i++) {
            if (charCount[s[i]] == 1) {
                return i; // Return the index of the first unique character
            }
        }

        // If no unique character exists, return -1
        return -1;
    }
    

    
};