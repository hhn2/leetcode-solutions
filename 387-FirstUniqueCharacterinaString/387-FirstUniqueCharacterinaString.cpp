class Solution {
public:
    // Function to check if a character exists in the map
    int contains(std::map<int, char>& myMap, char myChar) {
        for (auto it = myMap.begin(); it != myMap.end(); it++) {
            if (it->second == myChar) {
                return it->first; // Return the key (index)
            }
        }
        return -1; // Return -1 if not found
    }

    int firstUniqChar(std::string s) {
        std::map<int, char> myMap;
        std::set<char> repeated; // Track characters that have been repeated

        // Populate the map with unique characters
        for (int i = 0; i < s.length(); i++) {
            // Skip if the character is already marked as repeated
            if (repeated.find(s[i]) != repeated.end()) {
                continue;
            }

            int existingIndex = contains(myMap, s[i]);
            if (existingIndex == -1) {
                // Add character to the map with its index as the key
                myMap[i] = s[i];
            } else {
                // Remove character from the map if it's repeated
                myMap.erase(existingIndex);
                repeated.insert(s[i]); // Mark as repeated
            }
        }

        // Find the first unique character by iterating over the map
        if (!myMap.empty()) {
            return myMap.begin()->first; // The first key in the map
        }

        return -1; // No unique character found
    }
};
