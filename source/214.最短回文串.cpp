/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */

// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        if (len < 2) return s;

        int longest = 1;
        int start = 0;
        int end = 0;
        for (int i = 0; i <= len/2;) {
            start = i;
            end = i;
            while (end < len -1 && s[end] == s[end+1]) end++;
            i = end + 1;
            while (end < len -1 && start > 0 && s[start-1] == s[end+1]) {
                end++;
                start--;
            }

            if (start == 0 && longest < end - start + 1) {
                longest = end - start + 1;
            }
        }

        string remain = s.substr(longest, len - longest);
        reverse(remain.begin(), remain.end());
        return remain + s;
    }
};
// @lc code=end

