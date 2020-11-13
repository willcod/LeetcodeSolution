/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> memo(K + 1, vector<int>(N + 1, -1));
        return find(K, N, memo);
    }

    int find(int k, int n, vector<vector<int>>& memo) {
        if (n == 0 || n == 1) return n;
        if (k == 1) return n;
        if (memo[k][n] != -1) return memo[k][n];

        int ans = 10000;
        int l = 1, h = n;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int left = find(k - 1, mid - 1, memo);
            int right = find(k, n - mid, memo);
            ans = min(ans, max(left, right) + 1);

            if (left < right) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return memo[k][n] = ans;
    }
};
// @lc code=end
