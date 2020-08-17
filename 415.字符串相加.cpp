/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
// class Solution {
//  public:
//   string addStrings(string nums1, string nums2) {
//     int sum = 0;
//     int i = nums1.size() - 1;
//     int j = nums2.size() - 1;

//     string numRes;

//     while (i >= 0 || j >= 0 || sum > 0) {
//       if (i >= 0) sum += nums1[i--] - '0';
//       if (j >= 0) sum += nums2[j--] - '0';

//       numRes.insert(0, 1, sum % 10 + '0');
//       sum /= 10;
//     }

//     return numRes;
//   }
// };
// @lc code=end
