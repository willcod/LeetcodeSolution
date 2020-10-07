/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int findLength(vector<int>& A, vector<int>& B) {
        int lenA = A.size();
        int lenB = B.size();

        vector f(lenA + 1, vector(lenB + 1, 0));

        int maxlen = 0;
        for (int i = 1; i <= lenA; i++) {
            for (int j = 1; j <= lenB; j++) {
                if (A[i - 1] == B[j - 1])
                    f[i][j] = f[i - 1][j - 1] + 1;
                else
                    f[i][j] = 0;
                maxlen = max(f[i][j], maxlen);
            }
        }

        return maxlen;
    }
};
// @lc code=end
