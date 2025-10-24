'''
Author: Ali Çine
Description:
    First we sort the list to ensure that first elements are in ascending order. Then we loop every element in list with while loop. Because of later merges we must also compare new merge with next element from list, for that i use the last item (output[-1]) after checking that output list has valid length. If new merged list (output[-1]) doesnt overlap with item then i simply append item.
'''
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        i = 0
        intervals.sort() 
        output:List[List[int]] = []
        while i < n:
            if len(output) == 0:
                output.append(intervals[i])
            else:
                if output[-1][1] >= intervals[i][0]:
                    output[-1] = output[-1][0],max(output[-1][1],intervals[i][1])
                else:
                    output.append(intervals[i])
            i+= 1
        return output
