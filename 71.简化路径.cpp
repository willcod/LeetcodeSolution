/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> strs;
        string temp;

        while (getline(ss, temp, '/')) {
            if (temp == "." || temp == "")
                continue;
            else if (temp == ".." && strs.size()) {
                strs.pop_back();
            } else if (temp != "..") {
                strs.push_back(temp);
            }
        }

        string res = "";
        for (auto s : strs) {
            res += "/" + s;
        }

        return res.empty() ? "/" : res;
    }
};
// @lc code=end
