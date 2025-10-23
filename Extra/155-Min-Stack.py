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
