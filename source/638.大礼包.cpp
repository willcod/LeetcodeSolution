/*
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] 大礼包
 */
#include "cpp_includes.h"
// @lc code=start
bool operator< (vector<int>& a, int n){
    for (auto num : a) {
        if (num < n) return true;
    }

    return false;
}

void operator -= (vector<int>& a, vector<int>& b) { 
    for (int i = 0;i < a.size();i++){
        a[i] -= b[i];
    }
}

void operator += (vector<int>& a, vector<int>& b) { 
    for (int i = 0;i < a.size();i++){
        a[i] += b[i];
    }
}
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return shoppingOffers(price, special, needs, 0);
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost) {
        if (needs < 0) return INT_MAX;

        int m = inner_product(needs.begin(), needs.end(), price.begin(), cost);

        for (int i = 0; i < special.size(); i++) {
            needs -= special[i];
            m = min(m, shoppingOffers(price, special, needs, cost+special[i].back()));
            needs += special[i];
        }

        return m;
    }
};
// @lc code=end

