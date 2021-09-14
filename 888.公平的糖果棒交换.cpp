/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        if ((sumA + sumB) % 2) return {};

        unordered_set<int> setB{B.begin(), B.end()};

        int target = (sumA + sumB) / 2;
        for (int x : A) {
            int y = x + (sumB - sumA) / 2;
            if (setB.count(y)) return {x, y};
        }
        return {};
    }
};
// @lc code=end
