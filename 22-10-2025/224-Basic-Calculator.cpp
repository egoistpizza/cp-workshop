//
// Created by egoistpizza on 18.10.2025.
//

// 224. Basic Calculator
// https://leetcode.com/problems/basic-calculator/
// * Google & Meta Interview Question *

// Time: O(n)
// Memory: O(n)

class Solution {
public:
    int calculate(string s) {

        stack<int> stk;
        int result = 0;
        int sign = 1;
        int n = s.size();

        for (int i = 0; i < n; ++i) {

            char ch = s[i];

            if (isdigit(ch)) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                --i;
                result += sign * num;
            }
            else if (ch == '+') {
                sign = 1;
            }
            else if (ch == '-') {
                sign = -1;
            }
            else if (ch == '(') {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            }
            else if (ch == ')') {
                int prevSign = stk.top(); stk.pop();
                int prevResult = stk.top(); stk.pop();
                result = prevResult + prevSign * result;
            }
        }

        return result;
    }
};
