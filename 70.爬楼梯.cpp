/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;

        int oneStep = 1;
        int twoStep = 2;
        int all = 0;
        for (int i = 3; i <=n; i++) {
            all = oneStep + twoStep;
            oneStep = twoStep;
            twoStep = all;
        }

        return all;
    }
};
// @lc code=end

