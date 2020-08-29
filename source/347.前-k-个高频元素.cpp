/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */


// @lc code=start

struct cmp
{
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> freq;
        for (auto n : nums) {
            freq[n]++;
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;

        for (auto f : freq) {
            pq.push(f);
            if (pq.size() > k) pq.pop();
        }

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            result.push_back(p.first);
        }
        return result;
    }
};
// @lc code=end

