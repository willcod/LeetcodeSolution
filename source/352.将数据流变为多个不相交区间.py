#
# @lc app=leetcode.cn id=352 lang=python3
#
# [352] 将数据流变为多个不相交区间
#

# @lc code=start
from bisect import bisect_left

class SummaryRanges:

    def __init__(self):
        self.intervals = []
        self.s = set()

    def addNum(self, val: int) -> None:
        if val in self.s: return
        self.s.add(val)
        index = bisect_left(self.intervals, [val, val])

        if index < len(self.intervals) and self.intervals[index][0] -1 == val:
            self.intervals[index][0] = self.intervals[index][0] - 1
        elif index > 0 and self.intervals[index-1][1] + 1 == val:
            self.intervals[index-1][1] = self.intervals[index-1][1] + 1
        else:
            self.intervals.insert(index, [val, val])


    def getIntervals(self) -> List[List[int]]:
        connect = []
        for x in self.intervals:
            if connect and connect[-1][1] == x[0]-1:
                connect[-1][1] = x[1]
            else:
                connect.append(x)
        self.intervals = connect
        return self.intervals



# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(val)
# param_2 = obj.getIntervals()
# @lc code=end

