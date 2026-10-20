# Last updated: 10/19/2026, 10:19:25 PM
1class Solution:
2    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
3        prefixsum = [0]
4        for index, num in enumerate(nums):
5            prefixsum.append(prefixsum[-1]+num)
6
7        maxsum = float('-inf')
8        best = {}
9        for i in range(len(nums)):
10            if nums[i]-k in best and nums[i]+k in best:
11                if best[nums[i]-k] < best[nums[i]+k]:
12                    better = prefixsum[i+1] - best[nums[i]-k]
13                else:
14                    better = prefixsum[i+1] - best[nums[i]+k]
15                
16            elif nums[i]-k in best:
17                better = prefixsum[i+1] - best[nums[i]-k]
18            elif nums[i]+k in best:
19                better = prefixsum[i+1] - best[nums[i]+k]
20            else:
21                better = float('-inf')
22            if better > maxsum:
23                    maxsum = better
24            if nums[i] in best:
25                if best[nums[i]] > prefixsum[i]:
26                    best[nums[i]] = prefixsum[i]
27            else:
28                best[nums[i]] = prefixsum[i]
29
30
31        if maxsum == float('-inf'):
32            return 0
33        return maxsum
34                