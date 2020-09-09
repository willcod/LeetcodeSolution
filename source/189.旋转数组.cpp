/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;

    int count = 0;
    for (int start = 0; count < n; start++) {
      int currentPos = start;
      int currentVal = nums[start];

      do {
        int nextPos = (currentPos + k) % n;
        int nextVal = nums[nextPos];
        nums[nextPos] = currentVal;

        currentPos = nextPos;
        currentVal = nextVal;
        count++;
      } while (currentPos != start);
    }
  }
};
// @lc code=end
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};
