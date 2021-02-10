/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */
#include "cpp_includes.h"

class Solution {
   public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int ret = 1;
        int left = 0, right = 0;

        while (right < n - 1) {
            if (left == right) {
                if (arr[left] == arr[left + 1]) {
                    left++;
                }
                right++;
            } else {
                if (arr[right - 1] < arr[right] &&
                    arr[right] > arr[right + 1]) {
                    right++;
                } else if (arr[right - 1] > arr[right] &&
                           arr[right] < arr[right + 1]) {
                    right++;
                } else {
                    left = right;
                }
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};

class Solution {
   public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector f(arr.size(), vector(2, 1));
        int maxlen = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1])
                f[i][0] = f[i - 1][1] + 1;
            else if (arr[i] < arr[i - 1])
                f[i][1] = f[i - 1][0] + 1;

            maxlen = max({maxlen, f[i][0], f[i][1]});
        }
        return maxlen;
    }
};

// @lc code=start
class Solution {
   public:
    int maxTurbulenceSize(vector<int>& arr) {
        int inc = 1, dec = 1, maxlen = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) {
                dec = inc + 1;
                inc = 1;
            } else if (arr[i] > arr[i - 1]) {
                inc = dec + 1;
                dec = 1;
            } else {
                inc = 1;
                dec = 1;
            }
            maxlen = max({maxlen, inc, dec});
        }
        return maxlen;
    }
};
// @lc code=end
