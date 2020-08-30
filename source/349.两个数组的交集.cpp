/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> set1;
        unordered_set<int> set2;
        for (int n : nums1) {
            set1.insert(n);
        }

        for (int n : nums2) {
            if(set1.count(n)) {
                set2.insert(n);
            }
        }
        for (int n : set2) {
            result.push_back(n);
        }
        return result;
    }
};
// @lc code=end

