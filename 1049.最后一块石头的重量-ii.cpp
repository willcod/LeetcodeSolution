/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> f(1001, 0);
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                f[j] = max(f[j], f[j-stones[i]]+stones[i]);
            }
        }
        return sum - f[target]-f[target];
    }
};
// @lc code=end

