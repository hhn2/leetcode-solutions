// Last updated: 3/31/2026, 5:00:37 PM
1class Solution {
2public:
3    int candy(vector<int>& ratings) {
4
5        if (ratings.size() ==1){
6            return 1;
7        }
8        vector<int> answer;
9        answer.push_back(1);
10
11        int prev = ratings[0];
12        for (int i = 1; i < ratings.size(); i++){
13            if (ratings[i] > prev){
14                answer.push_back(answer[i-1] + 1);
15
16            }
17            
18            else{
19                answer.push_back(1);
20
21            }
22
23            prev = ratings[i];
24        }
25
26        prev = ratings[ratings.size()-1];
27   
28        for (int i = ratings.size()-2; i > -1; i--){
29            cout << i<< endl;
30            if(ratings[i]>prev){
31                if(answer[i]<=answer[i+1]){
32                    answer[i] = answer[i+1]+1;
33
34                }
35                
36            }
37            prev = ratings[i];
38        }
39
40        int count = 0;
41        for (int i = 0; i < ratings.size(); i ++){
42            count += answer[i];
43        }
44
45        return count;
46    }
47};