# Last updated: 7/2/2026, 11:17:58 PM
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """

        alist = []

        for char in s:
            if char in '({[':
                alist.append(char)
            elif char == ']' and (not alist or alist[-1] != '['):
                return False
            elif char == '}' and (not alist or alist[-1] != '{'):
                return False
            elif char == ')' and (not alist or alist[-1] != '('):
                return False  
            else:
                alist.pop()

        return not alist