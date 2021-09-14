/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */

// @lc code=start
class Solution {
 public:
  string getPermutation(int n, int k) {
      string res = "";
      vector<int> vec(n, 0);
      int f = 1;
      for (int i = 1; i <= n; i++) {
          vec[i-1] = i;
          f *= i;
      }

      while (n) {
          int cur_f =  f / n;
          f /= n;

          int index = (k - 1) / cur_f;
          res += vec[index] + '0';
          vec.erase(vec.begin()+index);
          k -= index * cur_f;
          n--;
      }
      return res;
  }
};
// @lc code=end