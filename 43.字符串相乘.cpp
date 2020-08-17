/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
 public:
  string multiply(string num1, string num2) {
    int n = num1.size();
    int m = num2.size();

    vector<int> pos(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        int mul = (num1[i] - '0') * (num2[j] - '0');
        int p1 = i + j;
        int p2 = i + j + 1;
        int sum = mul + pos[p2];
        pos[p1] += sum / 10;
        pos[p2] = sum % 10;
      }
    }

    stringstream sstr;
    for(auto e : pos) sstr << e;
    string result = sstr.str();
    int startPos = result.find_first_not_of("0");
    if (startPos != string::npos) {
      return result.substr(startPos);
    }

    return "0";
  }
};
// @lc code=end
