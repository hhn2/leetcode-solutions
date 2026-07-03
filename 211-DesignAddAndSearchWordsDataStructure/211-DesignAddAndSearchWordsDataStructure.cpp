// Last updated: 7/2/2026, 11:16:38 PM
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false) {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};


class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode;
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++){
            if(curr->children[word[i] - 97]){
                curr= curr->children[word[i]-97];
                if (i == word.length()-1 ){
                    curr->isEndOfWord = true;
                }
                
            }
            else{
                curr->children[word[i]-97] = new TrieNode;
                curr=curr-> children[word[i]-97];
                if (i == word.length()-1 ){
                    curr->isEndOfWord = true;
                }
            }

        }
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++){
            if(word[i]=='.'){
               
                for (int k = 0; k < 26; k++){

                    if(curr->children[k]){
                    if (searchfrom(word.substr(i+1), curr->children[k] )){
                        return true;
                     }
                    }
                
            }
            return false;
            }
            else if(curr->children[word[i] - 97]){
                curr= curr->children[word[i]-97];
            }
            
            
            else{
                return false;
            }
        }

        
        
         return curr->isEndOfWord;
        
    
    }

    bool searchfrom(string word, TrieNode* curr){
        if (!curr){
            return false;
        }
        for (int i = 0; i < word.length(); i++){
            if(word[i]=='.'){
                for (int k = 0;  k< 26; k++){
                    if(curr->children[k]){
                    if (searchfrom(word.substr(i+1), curr->children[k]) ){
                        return true;
                     }
                    }
                
                }   
                return false;
            }
            else if(curr->children[word[i] - 97]){
                curr= curr->children[word[i]-97];
            }
            
            else{
                return false;
            }

           
        }
         return curr->isEndOfWord;
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */