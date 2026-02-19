# Last updated: 2/19/2026, 1:34:58 PM
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        
        need = [0]*26
        window = [0]*26
        
        for c in s1:
            need[ord(c)-97] += 1
        
        for i in range(len(s2)):
            window[ord(s2[i])-97] += 1
            
            if i >= len(s1):
                window[ord(s2[i-len(s1)])-97] -= 1
            
            if window == need:
                return True
        
        return False
