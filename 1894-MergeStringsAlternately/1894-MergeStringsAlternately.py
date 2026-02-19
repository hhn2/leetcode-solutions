# Last updated: 2/19/2026, 1:34:38 PM
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        res = []
        
        for a, b in zip(word1, word2):
            res.append(a + b)
				
				#append everything left in the end of the longer word
        res.append(word1[len(word2):])
        res.append(word2[len(word1):])
				
				# this joins each charater together into one string
        return "".join(res)