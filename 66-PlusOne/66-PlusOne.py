# Last updated: 7/2/2026, 11:17:39 PM
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """

        
        if not digits:
            return [1]


        elif digits[-1] == 9:
            digits.pop()
            result = self.plusOne(digits)
            result.append(0)
            return result

        else:
            value = digits[-1]
            value += 1
            digits[-1] = value
            return digits
