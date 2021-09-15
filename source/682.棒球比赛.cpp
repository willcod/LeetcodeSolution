/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int calPoints(vector<string>& ops) {
        stack<int> score;
        int num = 0;
        for (auto s : ops) {
            if (s == "+") {
                int num1 = score.top();
                score.pop();
                int num2 = score.top();
                score.push(num1);
                score.push(num1 + num2);
            } else if (s == "C") {
                score.pop();
            } else if (s == "D") {
                score.push(2 * score.top());
            } else {
                score.push(atoi(s.c_str()));
            }
        }

        while (!score.empty()) {
            num += score.top();
            score.pop();
        }

        return num;
    }
};
// @lc code=end
