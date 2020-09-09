/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        int count = 0;
        int pre = 0;
        table[0] = 1;

        for (int n : nums) {
            pre += n;
            if (table.count(pre-k)) count += table[pre-k];
            table[pre]++;
        }

        return count;
    }
};
// @lc code=end

