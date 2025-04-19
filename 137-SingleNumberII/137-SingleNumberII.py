# Last updated: 4/19/2025, 5:46:32 PM
class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        # Initialize array to count bits (32 bits for integers)
        bits = [0] * 32
        
        # Count the bits at each position
        for num in nums:
            # Handle negative numbers by converting to 32-bit representation
            n = num & 0xFFFFFFFF if num < 0 else num
            
            for i in range(32):
                if (n >> i) & 1:
                    bits[i] += 1
                    bits[i] %= 3
        
        # Reconstruct the result
        result = 0
        for i in range(32):
            if bits[i]:
                result |= (1 << i)
        
        # Handle negative numbers (if the 31st bit is set)
        if bits[31]:
            # Convert back to negative in Python
            result = result - (1 << 32)
            
        return result