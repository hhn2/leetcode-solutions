// Last updated: 3/31/2026, 4:30:29 PM
1class Solution {
2public:
3    void rotate(vector<int>& nums, int k) {
4        if (nums.size()==1){
5            return;
6        }
7
8        if (k > nums.size()){
9            k = k%=nums.size();
10        }
11        reverse(0, nums.size()-1, nums);
12
13        reverse(0, k-1, nums);
14
15        reverse(k, nums.size()-1, nums);
16    
17    }
18
19    void reverse (int l, int r, vector<int>&nums){
20
21        while (l < r){
22            int temp = nums[r];
23            nums[r] = nums[l];
24            nums[l] = temp;
25            l++;
26            r--;
27        }
28
29    }
30      
31};