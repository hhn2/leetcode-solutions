class Solution {
public:
    char findTheDifference(string s, string t) {
        std::map<char, int> myMap;

        for (int i = 0; i < s.length(); i++){
            if(myMap.count(s[i]) == 1){
                myMap[s[i]]++;
            }
            else{
                myMap.emplace(s[i], 1);
            }
        }

        for (int i = 0; i < t.length(); i++){
            if (myMap.count(t[i]) == 0){
                return t[i];
            }
            else if (myMap.at(t[i]) == 0){
                return t[i]; 
            }
            else{
                myMap[t[i]]--;
            }
        }

       for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        if (it->second == 1){
            return it->first;
        }
    }
    return 0;
    }
};