/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string predictPartyVictory(string senate) {
        queue<int> r_que, d_que;
        int n = senate.length();
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                r_que.push(i);
            else
                d_que.push(i);
        }

        while (!r_que.empty() && !d_que.empty()) {
            int r = r_que.front(), d = d_que.front();
            r_que.pop(), d_que.pop();
            if (r < d) {
                r_que.push(r + n);
            } else {
                d_que.push(d + n);
            }
        }

        return r_que.empty() ? "Dire" : "Radiant";
    }
};
// @lc code=end
