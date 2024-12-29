class Solution:
    def checkValidString(self, s: str) -> bool:
        # Use two stacks to keep track of indices of '(' and '*' respectively
        stack_left = []
        stack_star = []
        
        # Iterate through the string
        for i, char in enumerate(s):
            if char == '(':
                stack_left.append(i)
            elif char == '*':
                stack_star.append(i)
            elif char == ')':
                if stack_left:
                    stack_left.pop()
                elif stack_star:
                    stack_star.pop()
                else:
                    return False
        
        # Match remaining '(' with '*' if possible
        while stack_left and stack_star:
            if stack_left[-1] > stack_star[-1]:
                return False  # '*' cannot match '(' in this position
            stack_left.pop()
            stack_star.pop()
        
        # Check if there are any unmatched '(' left
        return len(stack_left) == 0