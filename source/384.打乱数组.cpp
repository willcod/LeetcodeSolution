/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    vector<int> _cache;

    Solution(vector<int>& nums) : _cache(nums) {

    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _cache;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled(_cache);

        for (int i = _cache.size() - 1; i > 0; i--){
            swap(shuffled[i], shuffled[rand()%(i+1)]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

