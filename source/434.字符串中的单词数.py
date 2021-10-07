#
# @lc app=leetcode.cn id=434 lang=python3
#
# [434] 字符串中的单词数
#

# @lc code=start
class Solution:
    def countSegments(self, s: str) -> int:
        count = 0
        for i in range(len(s)) :
            if s[i] != ' ' and (i==0 or s[i-1] == ' '):
                count += 1
        return count
# @lc code=end

