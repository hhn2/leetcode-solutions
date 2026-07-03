# Last updated: 7/2/2026, 11:17:46 PM
class Solution:
    def jump(self, nums: List[int]) -> int:
        jumps = 0
        current_end = 0
        farthest = 0
        
        for i in range(len(nums) - 1):
            farthest = max(farthest, i + nums[i])
            
            # Time to use a jump
            if i == current_end:
                jumps += 1
                current_end = farthest

        return jumps
