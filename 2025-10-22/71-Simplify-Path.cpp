//
// Created by egoistpizza on 18.10.2025.
//

// 71. Simplify Path
// https://leetcode.com/problems/simplify-path/
// * Amazon Interview Question *

// Time: O(n)
// Memory: O(n)

class Solution {
public:
    string simplifyPath(string path) {

        deque<string> directoryStack;
        stringstream pathStream(path);
        string token;

        while (getline(pathStream, token, '/')) {
            if (token == "" || token == ".") continue;
            if (token == "..") {
                if (!directoryStack.empty())
                    directoryStack.pop_back();
            } else {
                directoryStack.push_back(token);
            }
        }

        if (directoryStack.empty())
            return "/";

        string simplifiedPath;

        for (const auto& directory : directoryStack)
            simplifiedPath += "/" + directory;

        return simplifiedPath;
    }
};
