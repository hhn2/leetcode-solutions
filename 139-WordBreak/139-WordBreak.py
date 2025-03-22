// Last updated: 3/22/2025, 7:42:17 PM
class Solution:
    def __init__(self):
        # Initialize Trie dict
        self.trie = {}

    # Method to insert into Trie
    def insert(self, word: str) -> None:
        node = self.trie
        for ch in word:
            if ch not in node:
                node[ch] = {}
            node = node[ch]
        node['$'] = {}

    # Method to search Trie
    def find_segments(self, s: str) -> bool:
        # return `False` if the first char itself isn't present in Trie
        if s[0] not in self.trie:
            return False

        # Search the Trie for all possible space-separated word sequences
        # recursively using a stack and return `True` if all words
        # in `s` are found, else return `False`
        n = len(s)
        stack = [0]
        while len(stack) > 0 and len(stack) < 50:  # Note: 50 was arbitrarily chosen
            node = self.trie
            i = stack.pop()
            while i < n:
                ch = s[i]
                if ch in node:
                    if '$' in node:
                        stack.append(i)
                    node = node[ch]
                    i += 1
                else:
                    if '$' not in node and len(stack) == 0:
                        return False
                    elif '$' not in node:
                        break
                    node = self.trie
            if '$' in node:
                return True
        return False

    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # Insert words in the `wordDict` into the Trie
        chars_in_dict = set()
        for word in wordDict:
            self.insert(word)
            for c in word:
                chars_in_dict.add(c)

        # Edge case-1: make sure unique chars in s are present in dict
        chars_in_s = set(s)
        if chars_in_s.intersection(chars_in_dict) != chars_in_s:
            return False

        # Find if s can be segmented into a space-separated sequence
        # of one or more words present in the Trie
        return self.find_segments(s)