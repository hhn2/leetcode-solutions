# Last updated: 10/4/2026, 10:51:44 PM
class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        curralt = 0
        altitudes = [curralt]  

        for i in gain:
            curralt += i
            altitudes.append(curralt)

        return max(altitudes)