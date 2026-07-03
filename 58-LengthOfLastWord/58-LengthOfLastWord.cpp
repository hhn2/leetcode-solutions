// Last updated: 7/2/2026, 11:17:41 PM
class Solution {
public:
    int lengthOfLastWord(string s) {
        std::istringstream iss(s); 
        std::string word;

        while (iss >>word){
            continue;
        }

        return word.length();  

        }
    };
        