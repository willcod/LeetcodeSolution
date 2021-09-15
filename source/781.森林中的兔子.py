#
# @lc app=leetcode.cn id=781 lang=python3
#
# [781] 森林中的兔子
#

# @lc code=start
class Solution(object):
    def numRabbits(self, answers):
        """
        :type answers: List[int]
        :rtype: int
        """
        answers.sort()
        i, ans = 0, 0
        while i < len(answers):
            cur = answers[i]
            ans += (cur+1)
            while cur > 0 and i + 1 < len(answers) and answers[i] == answers[i+1]:
                cur -= 1
                i += 1
            i += 1
        return ans
# @lc code=end

