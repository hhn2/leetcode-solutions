# Last updated: 11/8/2025, 9:26:06 PM
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        smallest = float('inf')
        middle = float('inf')
      
        for current_num in nums:
            
            if current_num > middle:
                return True
          
           
            if current_num <= smallest:
                smallest = current_num
            else:
                
                middle = current_num
      
        
        return False