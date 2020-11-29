/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */
#include "cpp_includes.h"
// @lc code=start
class JointSet {
    private:
    int count;
    vector<int> parent;
    vector<int> size;

    public:
    JointSet(int n) : count(n), parent(n, 0), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int Count() { return count;}

    int isConnect(int p, int q) {
        return find(p) == find(q);
    }

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void Union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);

        if (rootP == rootQ) return;
        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        } else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        JointSet js(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (M[i][j] == 1) js.Union(i,j);
            }
        }

        return js.Count();
    }
};
// @lc code=end

