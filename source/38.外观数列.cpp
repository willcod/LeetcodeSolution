/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string countAndSay(int n) {
        string s = "1";

        while(--n) {
            string cur = "";
            for (int i = 0; i < s.size(); i++) {
                int count = 1;
                while ((i+1)<s.size() && (s[i] == s[i+1])) {
                    count++;
                    i++;
                }

                cur += to_string(count)+s[i];
            }
            s = cur;
        }
        return s;
    }
};
// @lc code=end
