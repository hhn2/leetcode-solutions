class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        cur = "" #most recent directory
        
        for c in path + "/":
            if c == "/":
                if cur =="..":
                    if stack: stack.pop()
                elif cur != "" and cur != ".":
                    stack.append(cur)
                cur = ""
                
            else: cur += c
            
        return "/" + "/".join(stack) #join every string in the stack with a /