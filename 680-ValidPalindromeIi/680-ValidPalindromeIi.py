# Last updated: 2/19/2026, 1:34:54 PM
class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        left = 0
        right = len(s) - 1
        used = 0

        while left < right:
            if s[left] == s[right]:
                left += 1
                right -= 1
            elif used == 0:
                if s[left + 1] == s[right] and s[left] != s[right - 1]:
                    left += 1
                    used += 1
                elif s[left] == s[right - 1] and s[left + 1] != s[right]:
                    right -= 1
                    used += 1
                elif s[left + 1] == s[right] and s[left] == s[right - 1]:
                    # Need to check both possibilities here
                    return self.check_palindrome(s, left + 1, right) or self.check_palindrome(s, left, right - 1)
                else:
                    return False
            else:
                return False

        return True

    def check_palindrome(self, s, left, right):
        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1
        return True
