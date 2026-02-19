// Last updated: 2/19/2026, 1:34:43 PM
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> myMap;
        for (int i= 0; i < arr.size(); i++){
            if (myMap.count(arr[i]) == 1){
                myMap[arr[i]]++;
            }
            else{
                myMap.insert({arr[i], 1});
            }

        }
        set<int> mySet;
        for (auto it = myMap.begin(); it != myMap.end(); it++){
            if(mySet.count((*it).second)==1){
                return false;
            }
            else{
                mySet.insert ((*it).second);
            }
        }
        return true;
    }
};