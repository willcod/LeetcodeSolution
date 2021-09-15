#
# @lc app=leetcode.cn id=150 lang=python3
#
# [150] 逆波兰表达式求值
#

# @lc code=start
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            try:
                stack.append(int(token))
            except:
                num2 = stack.pop()
                num1 = stack.pop()
                stack.append(self.evaluate(num1, num2, token))
        return stack[0]

    def evaluate(self, num1, num2, op):
        if op == '+':
            return num1 + num2
        elif op == '-':
            return num1 - num2
        elif op == '*':
            return num1 * num2
        elif op == '/':
            return int(num1/num2)
# @lc code=end
