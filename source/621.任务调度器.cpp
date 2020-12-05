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
        unordered_map<char, int> map;
        int count = 0;
        for (char t : tasks) {
            map[t]++;
            count = max(count, map[t]);
        }

        int res = (count - 1) * (n + 1);

        for (auto t : map) {
            if (t.second == count) res++;
        }
        return max((int)tasks.size(), res);
    }
};
// @lc code=end

