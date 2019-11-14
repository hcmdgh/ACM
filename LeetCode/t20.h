#include <stack>

class Solution {
public:
    bool isValid(string s) {
        int size = s.length();
        stack<char> _stack;
        for (int i = 0; i < size; ++i) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{')
                _stack.emplace(ch);
            else if (ch == ')') {
                if (_stack.empty() || _stack.top() != '(')
                    return false;
                _stack.pop();
            } else if (ch == ']') {
                if (_stack.empty() || _stack.top() != '[')
                    return false;
                _stack.pop();
            } else if (ch == '}') {
                if (_stack.empty() || _stack.top() != '{')
                    return false;
                _stack.pop();
            }
        }
        return _stack.empty();
    }
};