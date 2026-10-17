# Last updated: 10/17/2026, 12:55:07 PM
1class Solution:
2    def removeDuplicates(self, nums: list[int]) -> int:
3        seenmax = -101
4        updated = 0
5        for num in nums:
6            if num == seenmax:
7                continue
8            elif num > seenmax:
9                seenmax = num
10                nums[updated] = seenmax
11                updated += 1
12
13        return updated
14        