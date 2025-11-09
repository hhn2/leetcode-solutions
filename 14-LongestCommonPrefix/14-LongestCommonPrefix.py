# Last updated: 11/8/2025, 9:37:23 PM
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        word = strs[0]
        for i in range(1, len(strs)):
            new_word = ""
            for j in range(len(strs[i])):
                if j < len(word) and strs[i][j] == word[j]:
                    new_word += strs[i][j]
                else:
                    break
            word = new_word
        return word