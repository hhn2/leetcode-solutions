// Last updated: 5/5/2025, 3:48:00 PM
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        int i = 0;
        while (j < s.length()){
            if (i == t.length()){
                return false;
            }
            if (s[j] == t[i]){
                j++;
                i++;
            }
            else{
                i++;
            }
        }
        return true;
    }
};