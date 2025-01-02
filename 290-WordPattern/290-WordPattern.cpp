class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::unordered_map<char, std::string> myMap;
        std::vector<std::string> myVec;
        std::set<std::string> mySet;

        std::istringstream iss(s); // Create a stream from the sentence
        std::string word;

        while (iss >> word) { // Extract each word from the stream
            myVec.emplace_back(word); // Process or print the word
        }

        if (pattern.length() != myVec.size()){
            return false;
        }
        for (int i = 0; i < pattern.length(); i++){
            if ((myMap.count(pattern[i]) == 1) && (myMap[pattern[i]] == myVec[i])){
                continue;
            }
            if ((myMap.count(pattern[i]) == 0) && (mySet.count(myVec[i]) == 0)){
                myMap.insert({pattern[i], myVec[i]});
                mySet.emplace(myVec[i]);
                continue;
            }
            return false;
        }

        return true;
    }
};