// Last updated: 11/8/2025, 11:09:57 PM
class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> res;
        vector<int> alphabetRecent(26, -1);
        for (int i = s.length()-1; i >= 0; i--){
            if (alphabetRecent[s[i]-97] == -1){
                alphabetRecent[s[i]-97] = i;
            }
        }
        int j = 0;
        while ( j < s.length()){
            if(alphabetRecent[s[j]-97] == j){
                res.push_back(1);
                j++;
            }
            else{
                int latest = alphabetRecent[s[j]-97];
                for (int q = j + 1; q < latest; q++){
                    if(alphabetRecent[s[q]-97] > latest){
                        latest = alphabetRecent[s[q]-97];
                    }
                }
                res.push_back(latest - j + 1);
                j = latest + 1;
            }
        }
        return res;
    }
};