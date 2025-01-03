class Solution {
public:
    string reverseWords(string s) {
        std::istringstream iss(s); 
        std::string word;
        std::vector<std::string> myVec;
        while (iss >> word) { 
            myVec.emplace_back(word);
        }
        std::string res;
        for (int i = myVec.size() - 1; i >= 0 ; i-- ){
            if(i == 0){
                res += myVec[i];
            }
            else{
            res = res + myVec[i] + " ";
            }
        }
        return res;

    }
};