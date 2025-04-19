# Last updated: 4/19/2025, 5:47:02 PM
class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        bits = [0] * 32
        
        for num in nums:
            n = num & 0xFFFFFFFF if num < 0 else num
            
            for i in range(32):
                if (n >> i) & 1:
                    bits[i] += 1
                    bits[i] %= 3
        
        result = 0
        for i in range(32):
            if bits[i]:
                result |= (1 << i)
        
        if bits[31]:
            result = result - (1 << 32)
            
        return result