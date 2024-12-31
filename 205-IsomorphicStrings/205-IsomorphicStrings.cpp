class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::map<char, char> myMap;

        for (int i = 0; i < s.length(); i++){
            if (myMap.count(s[i])){
                if (myMap.at(s[i]) == t[i]){
                    continue;
                }
                else{
                    return false;
                }

            }
            else{
                if (valueExists(myMap, t[i])){
                    return false;
                }
                myMap.emplace(s[i], t[i]);
            }

        }
        return true;
    }

    bool valueExists(const std::map<char, char>& myMap, const char& value) {
    for (const auto& pair : myMap) {
        if (pair.second == value) {
            return true;  // Value found
        }
    }
    return false;  // Value not found
}

};