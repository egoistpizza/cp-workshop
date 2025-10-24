'''
Author: Ali Çine
Description:
    For the 155.Question we dont create a new data structure, we only implement "getMin" function to appropriate "list" data structure.To calculate the minimum element at O(1) time complexity, we must return a variable that is ready in memory. We check in every push if minimum element has changed and update minstack. We use list for minstack because of pop function, if we didnt use a list then we wouldnt get previous minimum if new minimum was popped.
'''
class MinStack:
    def __init__(self):
        self.stack = []
        self.minstack = []

    def push(self, val:int) -> None:
        minnumber = self.getMin()
        if minnumber is not None:
            if val < minnumber:
                self.minstack.append(val)
            else:
                self.minstack.append(minnumber)
        else:
            self.minstack.append(val)
        self.stack.append(val)

    def pop(self) -> None:
        self.stack.pop()
        self.minstack.pop()

    def top(self) -> int:
        return self.stack[-1] if self.stack else None

    def getMin(self) -> int:
        return self.minstack[-1] if self.stack else None
