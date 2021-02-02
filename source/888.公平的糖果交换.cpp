/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 */
#include "cpp_includes.h"
// @lc code=start
// sumA - x + y = sumB + x - y
// 2(x-y) = sumB - sumA
// x - y = (sumB - sumA)/2
// x = y + (sumB - sumA)/2
class Solution {
   public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        unordered_set<int> setA(A.begin(), A.end());
        for (int y : B) {
            int x = y + (sumA - sumB) / 2;
            if (setA.count(x)) return {x, y};
        }

        return {};
    }
};
// @lc code=end
