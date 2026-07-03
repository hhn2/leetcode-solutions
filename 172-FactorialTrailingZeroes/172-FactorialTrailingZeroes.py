# Last updated: 7/2/2026, 11:16:45 PM
class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        while n > 0:
            n //= 5
            count += n
        return count
