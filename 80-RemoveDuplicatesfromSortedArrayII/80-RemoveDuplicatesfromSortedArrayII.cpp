// Last updated: 3/26/2026, 11:12:31 AM
1class Solution {
2public:
3    int removeDuplicates(vector<int>& nums) {
4        if (nums.size() == 1){
5            return 1;
6        }
7        int prev = nums[0];
8        int count = 1;
9        int pos = 1;
10        for (int i = 1; i  < nums.size(); i++){
11
12            if(prev == nums[i] && count == 2){
13                continue;
14            }
15            else if (prev==nums[i]){
16                count++;
17                nums[pos] = nums[i];
18                pos++;
19            }
20            else{
21                count = 1;
22                prev = nums[i];
23                nums[pos] = nums[i];
24                pos++;
25
26            }
27        }
28
29        return pos;
30
31        
32    }
33
34
35};