# Last updated: 7/2/2026, 11:17:44 PM
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:

        m = len(matrix)
        n = len(matrix[0])

        lbound = 0
        rbound = n - 1
        dbound = m - 1
        ubound = 1

        res: List[int] = []

        previ = 0
        prevj = -1
        nexti = 0
        nextj = 0

        while len(res) < m * n:
            res.append(matrix[nexti][nextj])

            # move right → down
            if (nextj == rbound) and (previ == nexti) and (prevj < nextj):
                rbound -= 1
                prevj = nextj
                nexti += 1

            # move down → left
            elif (nexti == dbound) and (prevj == nextj) and (previ < nexti):
                dbound -= 1
                previ = nexti
                nextj -= 1

            # move left → up
            elif (nextj == lbound) and (previ == nexti) and (prevj > nextj):
                lbound += 1
                prevj = nextj
                nexti -= 1

            # move up → right
            elif (nexti == ubound) and (prevj == nextj) and (previ > nexti):
                ubound += 1
                previ = nexti
                nextj += 1

            # continue right
            elif prevj < nextj:
                prevj = nextj
                nextj += 1

            # continue down
            elif previ < nexti:
                previ = nexti
                nexti += 1

            # continue left
            elif prevj > nextj:
                prevj = nextj
                nextj -= 1

            # continue up
            else:  # previ > nexti
                previ = nexti
                nexti -= 1

        return res