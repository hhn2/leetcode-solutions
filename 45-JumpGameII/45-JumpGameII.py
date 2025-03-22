// Last updated: 3/22/2025, 5:40:06 PM
class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        memo = {}

        def backtrack(i):
            if i >= n - 1:
                return 0  # No jumps needed if at or beyond the end
            
            if i in memo:
                return memo[i]
            
            min_jumps = float('inf')
            max_jump = nums[i]
            max_reachable_index = min(i + max_jump, n - 1)
            
            # Try all possible jumps
            for new_index in range(i + 1, max_reachable_index + 1):
                jumps_needed = backtrack(new_index)
                if jumps_needed != float('inf'):
                    min_jumps = min(min_jumps, jumps_needed + 1)
            
            memo[i] = min_jumps
            return min_jumps
        
        return backtrack(0)
