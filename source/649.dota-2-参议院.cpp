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
        queue<int> rq, dq;
        int n = senate.size();
        for (int i = 0; i < senate.size(); i++) {
            if (senate[i] == 'R') {
                rq.push(i);
            } else {
                dq.push(i);
            }
        }

        while (rq.size() && dq.size()) {
            int r = rq.front(); rq.pop();
            int d = dq.front(); dq.pop();

            if (r < d) {
                rq.push(r+n);
            } else {
                dq.push(d+n);
            }
        }

        return rq.empty() ? "Dire" : "Radiant";
    }
};
// @lc code=end

