#
# @lc app=leetcode.cn id=28 lang=python3
#
# [28] 实现 strStr()
#

# @lc code=start
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n, m = len(haystack), len(needle)
        offset = {needle[_]: _ for _ in range(m)}
        i = 0
        while i < n - m + 1:
            if haystack[i:i+m] == needle:
                return i
            else:
                if i < n - m and haystack[i+m] in needle:
                    step = m - offset[haystack[i+m]]
                else:
                    step = m + 1
                i += step
        return -1

# @lc code=end

