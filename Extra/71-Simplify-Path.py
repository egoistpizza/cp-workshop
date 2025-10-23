class Solution:
    def simplifyPath(self, path: str) -> str:
        path_list = path.split("/")
        stack = []
        to_return = ""
        for i in path_list:
            if i == "":
                continue
            if i == ".":
                continue
            elif i == "..":
                if len(stack) != 0:
                    stack.pop()
            else:
                stack.append(i)

        for element in stack:
            to_return += "/"+str(element)

        if len(stack) == 0:
            to_return = "/"

        return to_return
