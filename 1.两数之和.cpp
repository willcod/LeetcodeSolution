/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
// class Solution {
//  public:
//   vector<int> twoSum(vector<int>& nums, int target) {
//     unordered_map<int, int> hashMap;
//     vector<int> result;
//     for (int i = 0; i < nums.size(); i++) {
//       int numberNeedToFind = target - nums[i];

//       auto element = hashMap.find(numberNeedToFind);
//       if (element != hashMap.end()) {
//         return {element->second, i};
//       }

//       hashMap[nums[i]] = i;
//     }

//     return {0, 0};
//   }
// };

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> cache;

    for (int i = 0; i < nums.size(); i++) {
      int num2 = target - nums[i];
      if (cache.find(num2) != cache.end()) {
        return {cache[num2], i};
      }
      cache[nums[i]] = i;
    }

    return {0, 0};
  }
};
// @lc code=end
