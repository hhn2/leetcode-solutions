class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.length(); i++){
            if (haystack.length() - i < needle.length()){
                return -1;
            }
            if (haystack[i] == needle[0]){
                for (int j = 0; j < needle.length(); j++){
                    if (haystack[i+j]==needle[j] && j == needle.length() -1){
                        return i;
                    }
                    if (haystack[i+j]==needle[j]){
                        continue;
                    }
                    else{
                        break;
                    }
                }


            }
        }
        return -1;
    }
};