# Last updated: 2/19/2026, 1:34:40 PM
class Solution(object):
    def arrayStringsAreEqual(self, word1, word2):
        """
        :type word1: List[str]
        :type word2: List[str]
        :rtype: bool
        """
        mover = 1

        while mover < len(word1):
            word1[0] = word1[0] + word1[mover]
            mover += 1

        mover = 1

        while mover < len(word2):
            word2[0] = word2[0] + word2[mover]
            mover += 1

        if len(word1[0]) != len(word2[0]):
            return False

        mover = 0

        while mover < len(word1[0]):
            if word1[0][mover] != word2[0][mover]:
                return False
            mover += 1

        return True