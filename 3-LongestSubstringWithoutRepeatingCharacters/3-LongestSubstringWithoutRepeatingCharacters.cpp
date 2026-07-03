// Last updated: 7/2/2026, 11:18:03 PM
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //the character and the index of it
        map<char, int> seen;

        int maxsize = 0;
        int currsize = 0;

        
        int beginningindex = 0;
        for (int i = 0; i < s.size(); i++){
            
            //the character is not in the map "seen"
            if (seen.count(s[i]) == 0){

                seen.insert({s[i], i});
                currsize++;

                if (currsize > maxsize){
                    maxsize = currsize;
                }
            }
            //the character IS in the map
            else{

                //the character is the same as the first character in the substring
                if (s[i] == s[beginningindex]){

                    seen[s[i]] = i;
                    beginningindex++;
                }
                //the character is the same as some char in the substring
                else{

                    currsize -= (seen[s[i]] - beginningindex);

                    for (int j = beginningindex; j < seen[s[i]];  j++){
                        char todelete = s[j];

                        seen.erase(todelete);
                    }
                    if(seen[s[i]] + 1 < i){
                        beginningindex = seen[s[i]] + 1;
                    }
                    else{
                        beginningindex = i;
                    }
                    
                    seen[s[i]] = i;
                    
                    
                   

                }
            }
        }

        return maxsize;
    }


};