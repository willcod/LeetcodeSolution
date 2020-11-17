/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string decodeString(string s) {
        string res;
        stack<int> numstk;
        stack<string> strstk;

        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            } else if (isalpha(s[i])) {
                res += s[i];
            } else if (s[i] == '[') {
                numstk.push(num);
                num = 0;
                strstk.push(res);
                res = "";
            } else if (s[i] == ']') {
                int n = numstk.top();
                numstk.pop();

                for (int j = 0; j < n; j++) {
                    strstk.top() += res;
                }

                res = strstk.top();
                strstk.pop();
            }
        }
        return res;
    }
};
// @lc code=end
