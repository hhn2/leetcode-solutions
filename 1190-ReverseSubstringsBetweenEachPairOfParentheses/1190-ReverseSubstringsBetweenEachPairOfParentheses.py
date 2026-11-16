# Last updated: 11/15/2026, 7:43:49 PM
class Solution:
    def reverseParentheses(self, s: str) -> str:
        #.extend will add individual items from an araay to another array
        # use instead of .append bc this will just append the entire array 
        stack = []
        for c in s:
            if c == ')':
                toextend = []
                while True:
                    popped = stack.pop()
                    if popped == '(':
                        stack.extend(toextend)
                        break
                    else:
                        toextend.append(popped)
            else:
                stack.append(c)

            
        return "".join(stack)