class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        curralt = 0
        altitudes = [curralt]  

        for i in gain:
            curralt += i
            altitudes.append(curralt)

        return max(altitudes)