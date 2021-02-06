#
# @lc app=leetcode.cn id=8 lang=python3
#
# [8] 字符串转换整数 (atoi)
#

# @lc code=start

import re

class Solution:
    def myAtoi(self, s: str) -> int:
        INT_MAX = 2**31-1
        INT_MIN = -2**31
        s = s.lstrip()
        num_re = re.compile(r'^[\+\-]?\d+')
        num = num_re.findall(s)
        num = int(*num)
        return max(min(num, INT_MAX), INT_MIN)

# @lc code=end

