/*
 * @lc app=leetcode.cn id=535 lang=cpp
 *
 * [535] TinyURL 的加密与解密
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        i2url[count] = longUrl;
        return "http://" + to_string(count++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int last = shortUrl.find_last_of('/');
        int key = stol(shortUrl.substr(last+1));
        return i2url[key];
    }

    private:
    int count = 0;
    unordered_map<int, string> i2url;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end

