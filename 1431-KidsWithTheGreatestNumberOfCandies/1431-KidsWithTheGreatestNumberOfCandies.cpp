// Last updated: 10/4/2026, 10:51:56 PM
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