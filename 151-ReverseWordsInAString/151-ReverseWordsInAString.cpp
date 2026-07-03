// Last updated: 7/2/2026, 11:16:49 PM
class Solution {
public:
    string reverseWords(string s) {
        std::istringstream iss(s); 
        std::string word;
        std::vector<std::string> myVec;
        while (iss >> word) { 
            myVec.emplace_back(word);
        }
        std::string res;
        for (int i = myVec.size() - 1; i >= 0 ; i-- ){
            res += myVec[i];
            if (i != 0) {
                res += " ";
            }
        }
        return res;

    }
};