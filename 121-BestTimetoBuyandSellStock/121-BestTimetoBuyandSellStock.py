# Last updated: 10/17/2026, 11:40:48 AM
1class Solution:
2    def maxProfit(self, prices: list[int]) -> int:
3        buys = []
4        cheapest = prices[0]
5        for i in range(len(prices)):
6            if prices[i] < cheapest:
7                buys.append(prices[i])
8                cheapest = prices[i]
9                print(cheapest)
10            else:
11                buys.append(cheapest)
12                print(cheapest)
13        
14        expensive = prices[-1]
15        maxprofit = 0
16        for i in range(len(prices) - 1, -1, -1):
17            if prices[i] > expensive:
18                expensive = prices[i]
19            profit = expensive - buys[i] 
20            print(profit)
21            if profit > maxprofit:
22                maxprofit = profit
23            
24        return maxprofit
25            
26            
27            