// Last updated: 11/8/2025, 9:36:41 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string word = strs[0];
        for (int i = 1; i < strs.size(); i++){
            string newWord = "";
            for (int j = 0; j < strs[i].length(); j++){
                if (strs[i][j] == word[j]){
                    newWord += strs[i][j];
                }
                else {
                    break;
                }
            }
            word = newWord;
        }
        return word;
    }
};