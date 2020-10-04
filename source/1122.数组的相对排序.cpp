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
        int tmp = 0;
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < arr1.size(); j++) {
                if (arr1[j] == arr2[i]) {
                    swap(arr1[tmp++], arr1[j]);
                }
            }
        }

        sort(arr1.begin() + tmp, arr1.end());

        return arr1;
    }
};
// @lc code=end

class Solution {
   public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> hash;
        for (int i : arr1) hash[i]++;

        int pos = 0;
        for (auto i : arr2) {
            while (hash[i]-- > 0) arr1[pos++] = i;
        }

        for (auto kv : hash) {
            while (kv.second-- > 0) arr1[pos++] = kv.first;
        }

        return arr1;
    }
};