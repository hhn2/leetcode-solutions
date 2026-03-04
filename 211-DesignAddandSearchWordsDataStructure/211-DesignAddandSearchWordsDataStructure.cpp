// Last updated: 3/4/2026, 2:18:45 PM
1struct TrieNode {
2    TrieNode* children[26];
3    bool isEndOfWord;
4    TrieNode() : isEndOfWord(false) {
5        for (int i = 0; i < 26; ++i) children[i] = nullptr;
6    }
7};
8
9
10class WordDictionary {
11    TrieNode* root;
12public:
13    WordDictionary() {
14        root = new TrieNode;
15    }
16    
17    void addWord(string word) {
18        TrieNode* curr = root;
19        for (int i = 0; i < word.length(); i++){
20            if(curr->children[word[i] - 97]){
21                curr= curr->children[word[i]-97];
22                if (i == word.length()-1 ){
23                    curr->isEndOfWord = true;
24                }
25                
26            }
27            else{
28                curr->children[word[i]-97] = new TrieNode;
29                curr=curr-> children[word[i]-97];
30                if (i == word.length()-1 ){
31                    curr->isEndOfWord = true;
32                }
33            }
34
35        }
36    }
37    
38    bool search(string word) {
39        TrieNode* curr = root;
40        for (int i = 0; i < word.length(); i++){
41            if(word[i]=='.'){
42               
43                for (int k = 0; k < 26; k++){
44
45                    if(curr->children[k]){
46                    if (searchfrom(word.substr(i+1), curr->children[k] )){
47                        return true;
48                     }
49                    }
50                
51            }
52            return false;
53            }
54            else if(curr->children[word[i] - 97]){
55                curr= curr->children[word[i]-97];
56            }
57            
58            
59            else{
60                return false;
61            }
62        }
63
64        
65        
66         return curr->isEndOfWord;
67        
68    
69    }
70
71    bool searchfrom(string word, TrieNode* curr){
72        if (!curr){
73            return false;
74        }
75        for (int i = 0; i < word.length(); i++){
76            if(word[i]=='.'){
77                for (int k = 0;  k< 26; k++){
78                    if(curr->children[k]){
79                    if (searchfrom(word.substr(i+1), curr->children[k]) ){
80                        return true;
81                     }
82                    }
83                
84                }   
85                return false;
86            }
87            else if(curr->children[word[i] - 97]){
88                curr= curr->children[word[i]-97];
89            }
90            
91            else{
92                return false;
93            }
94
95           
96        }
97         return curr->isEndOfWord;
98        
99    }
100};
101
102/**
103 * Your WordDictionary object will be instantiated and called as such:
104 * WordDictionary* obj = new WordDictionary();
105 * obj->addWord(word);
106 * bool param_2 = obj->search(word);
107 */