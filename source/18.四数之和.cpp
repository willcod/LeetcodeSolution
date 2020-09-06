/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int targetof3 = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int targetof2 = targetof3 - nums[j];

                int f = j + 1;
                int b = nums.size() - 1;

                while (f < b) {
                    int sum = nums[f] + nums[b];
                    if (sum == targetof2) {
                        res.push_back({nums[i], nums[j], nums[f], nums[b]});
                        while (f < b && nums[f+1] == nums[f]) f++;
                        while (f < b && nums[b-1] == nums[b]) b--;
                        f++;
                        b--;
                    } else if (sum > targetof2) {
                        b--;
                    } else {
                        f++;
                    }
                }

                while ( j + 1 < nums.size() && nums[j] == nums[j+1]) j++;
            }
            while (i + 1 < nums.size() && nums[i] == nums[i+1]) i++;
        }

        return res;
    }
};
// @lc code=end

