# Last updated: 9/27/2025, 7:07:01 PM
class Solution:

    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n < 0:
            return self.myPow(1/x, -n)
        if n % 2 == 0:
            half = self.myPow(x, n // 2)
            return half * half#double slash for integer division
        return x * self.myPow(x, n-1)



