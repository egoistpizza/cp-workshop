#
# Created by egoistpizza on 8.10.2025.
#

# 274. H-Index
# https://leetcode.com/problems/h-index/

from typing import List

class Solution:
    def hIndex(self, citations: List[int]) -> int:

        n = len(citations)
        count = [0] * (n + 1)

        for c in citations:
            count[min(c, n)] += 1

        papers = 0

        for h in range(n, -1, -1):
            papers += count[h]

            if papers >= h:
                return h

        return 0
