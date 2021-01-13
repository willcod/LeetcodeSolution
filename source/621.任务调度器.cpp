/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> hash;
        int maxCount = 0;
        for (char t : tasks) {
            hash[t]++;
            maxCount = max(maxCount, hash[t]);
        }

        int cycles = (maxCount - 1) * (n + 1);

        for (auto kv : hash) {
            if (kv.second == maxCount) cycles += 1;
        }

        return max((int)tasks.size(), cycles);
    }
};
// @lc code=end
