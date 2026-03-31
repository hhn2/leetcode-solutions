// Last updated: 3/31/2026, 5:00:12 PM
1class Solution {
2public:
3    int candy(vector<int>& ratings) {
4
5        if (ratings.size() ==1){
6            return 1;
7        }
8        vector<int> answer;
9        answer.push_back(1);
10        //   cout <<"pushing "<< 1 << endl;
11        int prev = ratings[0];
12        for (int i = 1; i < ratings.size(); i++){
13            if (ratings[i] > prev){
14                answer.push_back(answer[i-1] + 1);
15                // cout <<"pushing "<< answer[i-1] + 1 << endl;
16            }
17            
18            else{
19                answer.push_back(1);
20                                // cout <<"pushing "<< 1 << endl;
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
31                //  cout <<"ratings[i] is "<< ratings[i] << endl;
32                //  cout << "prev is "<< prev << endl;
33                if(answer[i]<=answer[i+1]){
34                    answer[i] = answer[i+1]+1;
35                    //   cout <<"fixed to "<< answer[i] << endl;
36                }
37                
38            }
39            prev = ratings[i];
40        }
41
42        int count = 0;
43        for (int i = 0; i < ratings.size(); i ++){
44            count += answer[i];
45        }
46
47        return count;
48    }
49};