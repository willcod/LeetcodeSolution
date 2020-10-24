/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int len1 = arr1.size();
        int len2 = arr2.size();

        int temp = 0;
        for (int i = 0; i < len2; i++) {
            for (int j = 0; j < len1; j++) {
                if (arr1[j] == arr2[i]) {
                    swap(arr1[temp++], arr1[j]);
                }
            }
        }

        sort(arr1.begin() + temp, arr1.end());

        return arr1;
    }
};
// @lc code=end
