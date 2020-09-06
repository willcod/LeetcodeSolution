/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start

// 思路1: 遍历整个数组，用一个hash表来统计，一旦超过半数即返回该数,复杂度 O(n)
// 思路2: 排序，那么数组中间值，必为超过半数的值
// 思路3: 分治
// 思路4: 摩尔投票法
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int count = 0;
    int majority = 0;

    for (auto n : nums) {
      if (count == 0) {
        majority = n;
      }
      count += n == majority ? 1 : -1;
    }

    return majority;
  }
};
// @lc code=end

// nth_element 部分排序
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    return nums[nums.size() / 2];
  }
};

// sort 排序
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};

// hashtable counter
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> counter;
    for (int n : nums) {
      if (++counter[n] > nums.size() / 2) return n;
    }

    return 0;
  }
};