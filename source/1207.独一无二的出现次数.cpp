/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> eCount;

        for (int i = 0; i < arr.size(); i++) {
            eCount[arr[i]]++;
        }

        unordered_set<int> set;
        for (auto kv : eCount) {
            if (set.count(kv.second)) {
                return false;
            }
            set.insert(kv.second);
        }
        return true;
    }
};
// @lc code=end
