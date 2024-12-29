class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mylist = [0] * 26

        for char in s:
             mylist[ord(char.lower()) - ord('a')] += 1

        for char in t:
             mylist[ord(char.lower()) - ord('a')] -= 1



        for count in mylist:
            if count != 0:
                return False

        return True