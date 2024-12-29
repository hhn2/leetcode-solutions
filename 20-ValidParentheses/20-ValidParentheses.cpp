class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '{' || s[i] == '(' || s[i] == '['){
                myStack.push(s[i]);
            }
            else if (s[i] == ')'){
                if (myStack.empty() || myStack.top() != '('){
                    return false;
                }
                else {
                    myStack.pop();
                }

            }
            else if (s[i] == '}'){
                if (myStack.empty() || myStack.top() != '{'){
                    return false;
            }
            else {
                    myStack.pop();
                }

            }
            else if (s[i] == ']'){
                if (myStack.empty() || myStack.top() != '['){
                    return false;
            }
            else {
                    myStack.pop();
                }

            }
            
        }
        if (myStack.empty()){
        return true;}

        return false;
    }
};