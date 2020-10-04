/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */
#include "cpp_includes.h"
// @lc code=start

class JointSet {
   public:
    JointSet(int capacity)
        : _count(capacity), _master(capacity, 0), _size(capacity, 1) {
        for (int i = 0; i < capacity; i++) {
            _master[i] = i;
        }
    }

    int count() { return _count; }

    void join(int a, int b) {
        int mA = find(a);
        int mB = find(b);

        if (mA == mB) return;

        if (_size[mA] < _size[mB]) {
            _master[mA] = mB;
            _size[mB] += _size[mA];
        } else {
            _master[mB] = mA;
            _size[mA] += _size[mB];
        }
        _count--;
    }

   private:
    int find(int a) {
        while (_master[a] != a) {
            _master[a] = _master[_master[a]];
            a = _master[a];
        }
        return a;
    }

   private:
    int _count;
    vector<int> _master;
    vector<int> _size;
};
class Solution {
   public:
    int findCircleNum(vector<vector<int>>& M) {
        JointSet js(M.size());
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[0].size(); j++) {
                if (M[i][j] == 1) {
                    js.join(i, j);
                }
            }
        }
        return js.count();
    }
};
// @lc code=end
