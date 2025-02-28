class Solution {
public:
    bool isInSameRow(set<char>* rown, string& word){
                for (int i = 1; i < word.length(); i++){
                    if (rown->count(tolower(word[i])) == 0){
                        return false;
                    }
                }
                return true;
            }
    vector<string> findWords(vector<string>& words) {
        set<char> row1 = {'q','w','e','r', 't', 'y', 'u', 'i', 'o', 'p'};
        set<char> row2 = {'a','s','d','f', 'g','h','j','k','l'};
        set<char> row3 = {'z','x','c','v', 'b', 'n', 'm'};
        vector<string> res;
        

        for( int i = 0; i< words.size(); i++){
            set<char>* whichset = &row1;
            if(row2.count(tolower(words[i][0])) == 1){
                whichset = &row2;
            }
            else if (row3.count(tolower(words[i][0])) == 1){
                whichset = &row3;
            }

            if (isInSameRow(whichset, words[i])){
                res.push_back(words[i]);
            }
        }

        return res;

    }
};