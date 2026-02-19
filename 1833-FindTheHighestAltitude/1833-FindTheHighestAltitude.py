# Last updated: 2/19/2026, 1:34:39 PM
class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        curralt = 0
        altitudes = [curralt]  

        for i in gain:
            curralt += i
            altitudes.append(curralt)

        return max(altitudes)