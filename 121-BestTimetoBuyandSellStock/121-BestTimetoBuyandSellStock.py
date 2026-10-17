# Last updated: 10/17/2026, 11:44:43 AM
1class Solution:
2    def maxProfit(self, prices: list[int]) -> int:
3        minsofar = prices[0]
4        maxprofit = 0
5        for i in range(len(prices)):
6            if prices[i] - minsofar > maxprofit:
7                maxprofit = prices[i] - minsofar
8            if prices[i] < minsofar:
9                minsofar = prices[i]
10        return maxprofit
11            
12            
13            
14            