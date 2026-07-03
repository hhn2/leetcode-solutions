// Last updated: 7/2/2026, 11:16:23 PM
class Solution {
public:
    string reverseStr(string s, int k) {
       for (int i = 0; i < s.length(); i += (2*k)){

        int left = i; 
        int right;
        if (i + k > s.length()-1){
            right = s.length() -1;
        }
        else{right = i + k - 1;}

        while (left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
       }
 return s;
    }
   
};

 