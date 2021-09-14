/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;

        while (j < typed.size()) {
            if (i < name.length() && name[i] == typed[j]) {
                i++, j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            } else {
                return false;
            }
        }

        return i == name.length();
    }
};
// @lc code=end
