#
# @lc app=leetcode.cn id=409 lang=python3
#
# [409] 最长回文串
#

# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> int:
        count = [0]*128
        for c in s:
            count[ord(c)] += 1
        length = 0

        for i in count:
            length += i - (i&1)

        return length+1 if length < len(s) else length


# @lc code=end

