# Last updated: 7/2/2026, 11:18:00 PM
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        elif x < 10:
            return True
        elif x % 10 == 0:
            return False  # Numbers ending in 0 (except 0 itself) are not palindromes

        num_str = str(x)
        return self.check_palindrome(num_str)

    def check_palindrome(self, num_str):
        if len(num_str) <= 1:
            return True
        elif num_str[0] != num_str[-1]:
            return False
        else:
            return self.check_palindrome(num_str[1:-1])

