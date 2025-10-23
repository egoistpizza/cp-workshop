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

    def hasNext(self, intervals, i):
        try:
            intervals[i+1]
        except:
            return False
        else:
            return True
