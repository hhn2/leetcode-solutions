# Last updated: 5/29/2026, 1:13:38 AM
1class Solution:
2    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
3        charstostrings = {}
4        answer = []
5        for str in strs:
6            key = "".join(sorted(str))
7            if key in charstostrings:
8                charstostrings[key].append(str)
9            else:
10                charstostrings[key] = [str]
11        
12        return list(charstostrings.values())
13