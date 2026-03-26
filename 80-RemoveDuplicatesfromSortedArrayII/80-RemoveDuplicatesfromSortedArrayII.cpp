// Last updated: 3/26/2026, 11:11:38 AM
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
12            //3rd or moreth occurrence of the same 
13            if(prev == nums[i] && count == 2){
14                continue;
15                cout<<"third or moreth of"<< nums[i];
16    
17            }
18            //1st or 2nd occurrence
19            else if (prev==nums[i]){
20                count++;
21                nums[pos] = nums[i];
22                pos++;
23                cout<<"first or second of" <<nums[i];
24            }
25            //different num
26            else{
27                count = 1;
28                prev = nums[i];
29                nums[pos] = nums[i];
30                pos++;
31                cout<<"new num"<< nums[i];
32
33            }
34        }
35
36        return pos;
37
38        
39    }
40
41
42};