/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = s.length();
        for (int i = 1; i <=3; i++) {
            for (int j = 1; j <= 3 && (i+j)<n; j++) {
                for (int k = 1; k <= 3 && (i+j+k) < n;k++) {
                    auto a = s.substr(0, i);
                    auto b = s.substr(i, j);
                    auto c = s.substr(i+j, k);
                    auto d = s.substr(i+j+k);

                    if (isValid(a)&&isValid(b)&&isValid(c)&&isValid(d)) {
                        res.push_back(a+"."+b+"."+c+"."+d);
                    }
                }
            }
        }
        return res;
    }

    bool isValid(string ip) {
        return ip.length() > 0 && ip.length() <= 3 && stoi(ip) <= 255 && (ip[0] != '0' || ip.length() == 1);
    }
};
// @lc code=end

