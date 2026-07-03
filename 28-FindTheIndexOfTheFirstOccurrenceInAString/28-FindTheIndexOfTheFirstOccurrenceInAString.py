# Last updated: 7/2/2026, 11:17:56 PM
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        #needle's entire legnth has to be able to fit within haystack
        for i in range(len(haystack) - len(needle) + 1):
            #for each iteration we only look at the length of the needle starting at that round of iteration
            if haystack[i:i+len(needle)] == needle:
                return i

        return -1