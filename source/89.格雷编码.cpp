/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<int> grayCode(int n) {
        int shift = 1;
        vector<int> res;

        while (n >= 0) {
            if (res.empty()) {
                res.push_back(0);
            } else {
                for (int i = shift - 1; i >= 0; i--) {
                    res.push_back(res[i] + shift);
                }
                shift *= 2;
            }
            n--;
        }
        return res;
    }
};
// @lc code=end
