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
        