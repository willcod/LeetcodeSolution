/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, true);
        int count = 0;

        for (int i=2; i < n; i++) {
            if (primes[i]) {
                count++;

                if ((long)i*i < n) {
                    for (int j = i*i; j < n; j+=i) {
                        primes[j] = false;
                    }
                }
            }
        }

        return count;
    }
};
// @lc code=end

