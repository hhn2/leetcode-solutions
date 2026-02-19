# Last updated: 2/19/2026, 1:35:06 PM
class Solution:
    def reverseVowels(self, s: str) -> str:
        word = list(s)
        start = 0
        end = len(s) - 1
        vowels = set("aeiouAEIOU")  # Using a set for vowels

        while start < end:
            while start < end and word[start] not in vowels:
                start += 1

            while start < end and word[end] not in vowels:
                end -= 1

            word[start], word[end] = word[end], word[start]

            start += 1
            end -= 1

        return "".join(word)