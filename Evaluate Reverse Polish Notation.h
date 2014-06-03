// Evaluate Reverse Polish Notation
/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        for (int i=0; i<tokens.size(); ++i) {
            if (tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/") {
                stk.push(stoi(tokens[i]));
            } else { 
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                if (tokens[i] == "+") stk.push(a+b);
                else if (tokens[i] == "-") stk.push(a-b);
                else if (tokens[i] == "*") stk.push(a*b);
                else if (tokens[i] == "/") stk.push(a/b);
            }
        }
        return stk.top();
    }
};