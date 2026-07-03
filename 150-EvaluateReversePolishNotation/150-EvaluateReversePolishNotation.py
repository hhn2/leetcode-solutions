# Last updated: 7/2/2026, 11:16:48 PM
class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        
        stack = []
        for s in tokens:
            if s == "+":
                b = stack.pop()
                a = stack.pop()
                stack.append(a + b)
            elif s == "-":
                b = stack.pop()
                a = stack.pop()
                stack.append(a - b)
            elif s == "*":
                b = stack.pop()
                a = stack.pop()
                stack.append(a * b)
            elif s =="/":
                b = stack.pop()
                a = stack.pop()
                stack.append(int(a / b) if a * b >= 0 else -(-a // b))

            else: 
                stack.append(int(s))

        
        return stack[-1]
        

           
