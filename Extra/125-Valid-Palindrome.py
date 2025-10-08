# 125. Valid Palindrome

# https://leetcode.com/problems/valid-palindrome/

class Solution:
    def isPalindrome(self, s: str) -> bool:
        import re
        cleaned = re.sub(r'[^a-zA-Z0-9]', '', s)
        a = cleaned.lower()
        return a == a[::-1]