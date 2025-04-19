# Last updated: 4/19/2025, 5:33:13 PM
class Solution:
    def singleNumber(self, nums):
        ones = 0
        twos = 0
        for num in nums:
            ones = (ones ^ num) & ~twos
            twos = (twos ^ num) & ~ones
        return ones