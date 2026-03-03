// Last updated: 3/3/2026, 4:27:26 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
15        
16        vector<vector<TreeNode*>> answer;
17        vector<vector<int>> hello;
18        if (!root){
19            return hello;
20        }
21        vector<TreeNode*> first;
22
23        first.push_back(root);
24        answer.push_back(first);
25
26        helper(answer, false, 0);
27        return translator(answer);
28    }
29
30    void helper(vector<vector<TreeNode*>>& answer, bool isRight, int index){
31        if (index == answer.size()){
32            return;
33        }
34        
35        int currLen = answer.size();
36
37        
38            if (isRight){
39                for(int i = answer[index].size()-1; i > -1; i--){
40                if(answer[index][i]->left){
41                    if (answer.size() == currLen){
42                        vector<TreeNode*> topush;
43                        topush.push_back(answer[index][i]->left);
44                        answer.push_back(topush);
45                    }
46                    else {
47                        answer[currLen].push_back(answer[index][i]->left);
48                    }
49                }
50                if (answer[index][i]->right){
51                    if (answer.size() == currLen){
52                        vector<TreeNode*> topush;
53                        topush.push_back(answer[index][i]->right);
54                        answer.push_back(topush);
55                    }
56                    else {
57                        answer[currLen].push_back(answer[index][i]->right);
58                    }
59                }
60
61            }
62            }
63            else{
64                for(int i = answer[index].size()-1; i > -1; i--){
65                if (answer[index][i]->right){
66                    if (answer.size() == currLen){
67                        vector<TreeNode*> topush;
68                        topush.push_back(answer[index][i]->right);
69                        answer.push_back(topush);
70                    }
71                    else {
72                        answer[currLen].push_back(answer[index][i]->right);
73                    }
74                }
75                if(answer[index][i]->left){
76                    if (answer.size() == currLen){
77                        vector<TreeNode*> topush;
78                        topush.push_back(answer[index][i]->left);
79                        answer.push_back(topush);
80                    }
81                    else {
82                        answer[currLen].push_back(answer[index][i]->left);
83                    }
84                }
85
86            }
87            }
88            index++;
89        
90        
91        helper(answer, !isRight, index);
92
93    }
94
95    vector<vector<int>> translator(vector<vector<TreeNode*>>& answer){
96        vector<vector<int>> toreturn; 
97        for(int i = 0; i < answer.size(); i++){
98            vector<int> topush;
99            for (int j = 0; j < answer[i].size(); j++){
100                topush.push_back(answer[i][j]->val);
101            }
102            toreturn.push_back(topush);
103        }
104        return toreturn;
105    }
106
107};