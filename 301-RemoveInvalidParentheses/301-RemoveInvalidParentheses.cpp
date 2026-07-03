// Last updated: 7/2/2026, 11:16:28 PM
class Solution {
public:
    vector<string> result;
    unordered_set<string> seen;

    vector<string> removeInvalidParentheses(string s) {
        int openrem = 0;
        int closerem = 0;

        // count minimum removals needed
        for (char c : s) {
            if (c == '(') {
                openrem++;
            } 
            else if (c == ')') {
                if (openrem > 0) {
                    openrem--;
                } else {
                    closerem++;
                }
            }
        }

        string current;
        backtrack(s, 0, openrem, closerem, 0, current);

        return result;
    }

    void backtrack(const string& s,
                   int index,
                   int openrem,
                   int closerem,
                   int balance,
                   string& current) {

        // invalid state
        if (openrem < 0 || closerem < 0 || balance < 0) {
            return;
        }

        // not enough chars left to close all opens
        if (balance > s.length() - index) {
            return;
        }

        // finished processing
        if (index == s.length()) {
            if (openrem == 0 && closerem == 0 && balance == 0) {

                if (!seen.count(current)) {
                    seen.insert(current);
                    result.push_back(current);
                }
            }
            return;
        }

        char c = s[index];

        // OPTION 1: remove current parenthesis

        if (c == '(') {
            backtrack(s,
                      index + 1,
                      openrem - 1,
                      closerem,
                      balance,
                      current);
        }

        if (c == ')') {
            backtrack(s,
                      index + 1,
                      openrem,
                      closerem - 1,
                      balance,
                      current);
        }

        // OPTION 2: keep current character

        current.push_back(c);

        if (c != '(' && c != ')') {

            backtrack(s,
                      index + 1,
                      openrem,
                      closerem,
                      balance,
                      current);

        } 
        else if (c == '(') {

            backtrack(s,
                      index + 1,
                      openrem,
                      closerem,
                      balance + 1,
                      current);

        } 
        else if (balance > 0) {

            backtrack(s,
                      index + 1,
                      openrem,
                      closerem,
                      balance - 1,
                      current);
        }

        current.pop_back();
    }
};