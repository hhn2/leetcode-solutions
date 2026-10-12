# Last updated: 10/11/2026, 8:54:23 PM
1class Solution:
2    def numDecodings(self, s: str) -> int:
3        dp = {}
4        return self.rec(s, dp)
5    def rec(self,rem, dp):
6        if rem in dp:
7            return dp[rem]
8        if len(rem) == 0 or rem[0] == '0':
9            dp[rem] = 0
10            return dp[rem]
11        if len(rem) == 1:
12            dp[rem] = 1
13            return dp[rem]
14        if len(rem) == 2:
15            if (int(rem[0]) >= 3) or (int(rem[0]) == 2 and int(rem[1]) >= 7):
16                dp[rem] = self.rec(rem[1:], dp) 
17                
18            elif (int(rem[1]) == 0):
19                dp[rem] = 1
20            else:
21                dp[rem] = 2
22            return dp[rem]
23        if (int(rem[0]) >= 3) or (int(rem[0]) == 2 and int(rem[1]) >= 7):
24            dp[rem] = self.rec(rem[1:], dp) 
25            # print (rem + "is" + dp[rem])
26
27        else:
28            dp[rem] = (self.rec(rem[1:], dp) + self.rec(rem[2:], dp))
29            print (rem + "is" + str(dp[rem]))
30        return dp[rem]