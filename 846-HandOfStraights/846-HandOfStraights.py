# Last updated: 10/4/2026, 10:52:20 PM
class Solution(object):
    def isNStraightHand(self, hand, groupSize):
        """
        :type hand: List[int]
        :type groupSize: int
        :rtype: bool
        """
        if len(hand) % groupSize != 0:
            return False
        
        from collections import Counter
        count = Counter(hand)
        
        while count:
            min_card = min(count)
            
            for num in range(min_card, min_card + groupSize):
                if count[num] == 0:
                    return False
                count[num] -= 1
                if count[num] == 0:
                    del count[num]
                    
        return True
