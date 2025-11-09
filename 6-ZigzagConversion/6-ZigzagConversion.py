# Last updated: 11/8/2025, 8:22:37 PM
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        
        # cycles = len(s) / (2 * numRows - 2)
        # numCycles = math.ceil(cycles)
        # numCols = numCycles * (numRows - 1)
        
        myVec = [''] * numRows
        
        i = 0  # rows
        isVertical = True
        t = 0
        
        while t < len(s):
            if isVertical:
                while i < numRows and t < len(s):
                    myVec[i] += s[t]
                    t += 1
                    i += 1
                
                isVertical = False
                i -= 2
            else:
                for q in range(numRows - 2):
                    if t >= len(s):
                        break
                    myVec[i] += s[t]
                    t += 1
                    i -= 1
                
                isVertical = True
        
        return ''.join(myVec)

        