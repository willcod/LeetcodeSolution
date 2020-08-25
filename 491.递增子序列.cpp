/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> subseq;
    backtracking(nums, result, subseq, 0);
    return result;
  }

 private:
  void backtracking(vector<int>& nums, vector<vector<int>>& result,
                    vector<int>& subseq, int startIndex) {
    if (subseq.size() > 1) {
        result.push_back(subseq);
    }
    int hash[201] = {0};

    for (int i = startIndex; i < nums.size(); i++) {
        if ((subseq.empty() || nums[i] >= subseq.back()) && hash[nums[i]+100] == 0) {
            subseq.push_back(nums[i]);
            backtracking(nums,result, subseq, i+1);
            subseq.pop_back();
            hash[nums[i]+100] = 1;
        }
    }
  }
};
// @lc code=end
