# Last updated: 5/29/2026, 1:42:45 AM
1class Solution:
2    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
3        freq = {}
4        for num in nums:
5            if num in freq:
6                freq[num]+=1
7            else:
8                freq[num] = 1
9            
10        max_heap = [(-value, key) for key, value in freq.items()]
11        heapq.heapify(max_heap)
12
13        answer = []
14        for i in range(k):
15            item = heapq.heappop(max_heap)
16            answer.append(item[1])
17
18        return answer
19