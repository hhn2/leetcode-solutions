class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s) - 1

        while left < right:
            # Skip non-alphabetic characters
            while left < right and (not s[left].isalnum() or s[left] == " "):
                left += 1
            while left < right and (not s[right].isalnum() or s[right] == " "):
                right -= 1

            # Convert characters to lowercase for comparison
            left_char = s[left].lower()
            right_char = s[right].lower()

            # Compare characters
            if left_char != right_char:
                return False

            left += 1
            right -= 1

        return True


        