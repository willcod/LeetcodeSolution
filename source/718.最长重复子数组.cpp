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
        int m = A.size();
        int n = B.size();

        vector f(m+1, vector(n+1, 0));
        int len = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A[i-1] == B[j-1]){
                    f[i][j] = f[i-1][j-1]+1;
                }
                len = max(len, f[i][j]);
            }
        }
        return len;
    }
};
// @lc code=end

