#
# @lc app=leetcode.cn id=1006 lang=python
#
# [1006] 笨阶乘
#

# @lc code=start
class Solution(object):
    def clumsy(self, N):
        """
        :type N: int
        :rtype: int
        """
        op = 0
        stack = [N]
        for i in range(N-1, 0, -1):
            if op == 0:
                stack.append(stack.pop()*i)
            elif op == 1:
                stack.append(int(stack.pop()/float(i)))
            elif op == 2:
                stack.append(i)
            elif op == 3:
                stack.append(-i)
            
            op = (op+1) % 4
        
        return sum(stack)
# @lc code=end

