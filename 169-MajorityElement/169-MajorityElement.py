# Last updated: 7/2/2026, 11:16:46 PM
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        m = defaultdict(int)

        for num in nums:
            m[num] += 1
        n = n // 2
        for key, value in m.items():
            if value > n:
                return key
        
        return 0