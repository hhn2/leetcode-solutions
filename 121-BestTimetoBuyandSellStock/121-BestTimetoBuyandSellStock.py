# Last updated: 10/17/2026, 11:46:07 AM
1class Solution:
2    def maxProfit(self, prices: list[int]) -> int:
3        minsofar = prices[0]
4        maxprofit = 0
5        for price in prices:
6            if price - minsofar > maxprofit:
7                maxprofit = price - minsofar
8            if price < minsofar:
9                minsofar = price
10        return maxprofit
11            
12            
13            
14            