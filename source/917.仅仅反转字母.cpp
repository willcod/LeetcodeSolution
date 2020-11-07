/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string reverseOnlyLetters(string S) {
        int left = 0;
        int right = S.length() - 1;

        while (left < right) {
            while (left < right && !isalpha(S[left])) left++;
            while (left < right && !isalpha(S[right])) right--;

            swap(S[left++], S[right--]);
        }

        return S;
    }
};
// @lc code=end
