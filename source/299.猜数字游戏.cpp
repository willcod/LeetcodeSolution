/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int cow = 0;

        int count[10] = {0, 0};

        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) bull++;
            else {
                if (count[secret[i]-'0']++ < 0) cow++;
                if (count[guess[i]-'0']-- > 0) cow++;
            }
        }

        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};
// @lc code=end

