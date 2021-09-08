/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1;
        int hi = n;

        return firstBadVersion(lo, hi);
    }

    int firstBadVersion(int lo, int hi){
        if (lo >= hi) return lo;

        int mid = lo + (hi-lo)/2;

        if (isBadVersion(mid)) {
            return firstBadVersion(lo, mid);
        } else {
            return firstBadVersion(mid+1, hi);
        }
    }
};
// @lc code=end

