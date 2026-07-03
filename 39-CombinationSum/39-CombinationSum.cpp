// Last updated: 7/2/2026, 11:17:49 PM
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> current; 
        backtrack(answer, 0, target, candidates, current, 0);
        return answer;
    }

    void backtrack(vector<vector<int>>& answer, int index, int target, vector<int>& candidates, vector<int>& current, int currsum){
       //ready to add to vector
        if (currsum == target){
            answer.push_back(current);
            return;
        }

        if (index >= candidates.size() || currsum > target){
            return;
        }
        //take this number
             current.push_back(candidates[index]);
            backtrack(answer, index, target, candidates, current, currsum + candidates[index]);
            current.pop_back();

         //skip this number
         backtrack(answer, index + 1, target, candidates, current, currsum);
        
    }
};