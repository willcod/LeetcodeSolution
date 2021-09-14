/*
 * @lc app=leetcode.cn id=93 lang=javascript
 *
 * [93] 复原IP地址
 */

// @lc code=start
/**
 * @param {string} s
 * @return {string[]}
 */
var restoreIpAddresses = function (s) {
    const res = [];
    const ips = [];

    const isValid = s => {
        return s.length > 0 && 
        s.length <= 3 && 
        parseInt(s) <= 255 && 
        (s[0] != '0' || s.length == 1);
    }

    const findIp = index => {
        if (ips.length == 4) {
            if (index == s.length)
                res.push(ips.join("."));
            return;
        }

        let curNum = '';
        for (let i = index; i < s.length && i < index + 3; i++) {
            curNum += s[i];
            if (isValid(curNum)) {
                ips.push(curNum);
                findIp(i + 1);
                ips.pop();
            }
        }
    }

    findIp(0);
    return res;
};
// @lc code=end

