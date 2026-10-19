# Last updated: 10/19/2026, 6:45:43 PM
1class Solution:
2    def nextGreaterElement(self, nums1: list[int], nums2: list[int]) -> list[int]:
3        n1indices = {}
4        for i, num1 in enumerate(nums1):
5            n1indices[num1] = i
6
7        
8        monostack = []
9        answer = [-1] * len(nums1)
10        for j, num2 in enumerate(nums2):
11            if monostack:
12                while monostack and monostack[-1] < num2:
13                    toclear = monostack.pop()
14                    print("need to clear" , str(toclear))
15                    answer[n1indices[toclear]] = num2
16            if num2 in n1indices:
17                monostack.append(num2)
18
19        return answer
20
21
22