// Last updated: 2/19/2026, 1:34:48 PM
class Solution {
public:
    int fib(int n) {
        if (n <= 1){
            return n;
        }
        return (fib(n-1)+fib(n-2));
    }
};