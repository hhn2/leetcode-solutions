// Last updated: 2/19/2026, 1:34:44 PM
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = -1;
        for (int i = 0; i < candies.size(); i++){
            if (candies[i] > max){
                max = candies[i];
            } 
        }
        vector<bool> answer;
        for (int i = 0; i < candies.size(); i++){
            if (candies[i] + extraCandies >= max){
                answer.emplace_back(true);
            
            }
            else{
                answer.emplace_back(false);
            }
        }
        return answer;
    }
};