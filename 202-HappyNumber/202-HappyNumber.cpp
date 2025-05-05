// Last updated: 5/5/2025, 4:19:48 PM
class Solution {
public:

    int findSum(int n){
        if (n < 10){
            return n*n;
        }
        return ((n % 10)*(n%10) + findSum(n/10));
    }
    bool isHappy(int n) {
        set<int> Seen;
        Seen.insert(n);
        while (true){
            int interest = findSum(n);
            n = interest;
            
            if (interest == 1){
                return true;
            }
            
            if (Seen.find(interest) != Seen.end()){
                return false;
            }
            Seen.insert(interest);
            

        }
        
    } 
};