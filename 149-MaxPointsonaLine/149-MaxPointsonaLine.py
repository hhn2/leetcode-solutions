# Last updated: 9/27/2025, 7:39:22 PM
from math import gcd
from collections import defaultdict

class Solution:
    def maxPoints(self, points: list[list[int]]) -> int:
        n = len(points)
        if n <= 2:
            return n

        result = 0

        for i in range(n):
            slopes = defaultdict(int)
            same_point = 1  
            curr_max = 0

            for j in range(i + 1, n):
                dx = points[j][0] - points[i][0]
                dy = points[j][1] - points[i][1]

            
                g = gcd(dx, dy)
                if g != 0:
                    dx //= g
                    dy //= g

          
                if dx == 0:
                    dy = 1
                elif dy == 0:
                    dx = 1
                elif dx < 0:  
                    dx = -dx
                    dy = -dy

                slopes[(dx, dy)] += 1
                curr_max = max(curr_max, slopes[(dx, dy)])

            result = max(result, curr_max + same_point)

        return result
