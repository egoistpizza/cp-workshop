//
// Created by egoistpizza on 18.10.2025.
//

// 155. Min Stack
// https://leetcode.com/problems/min-stack/
// * Amazon Interview Question *

// Time: O(1) for all operations
// Memory: O(n)

class MinStack {
private:

    stack<int> stack;
    stack<int> minStack;

public:

    MinStack() {}

    void push(int val) {
        stack.push(val);
        val = min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }

    void pop() {
        stack.pop();
        minStack.pop();
    }

    int top() {
        return stack.top();
    }

    int getMin() {
        return minStack.top();
    }
};
