/*
 * @lc app=leetcode.cn id=70 lang=javascript
 *
 * [70] 爬楼梯
 */

// @lc code=start
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    var allways = 0;
    var oneStep = 1;
    var twoStep = 2;

    for (i = 3; i <= n; i++) {
        allways = oneStep + twoStep;
        oneStep = twoStep;
        twoStep = allways;
    }

    return allways;
};
// @lc code=end

