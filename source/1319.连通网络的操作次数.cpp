/*
 * @lc app=leetcode.cn id=1319 lang=cpp
 *
 * [1319] 连通网络的操作次数
 */
#include "cpp_includes.h"
// @lc code=start
class UniSet {
   private:
    vector<int> parent;  // 记录节点的根
    vector<int> rank;    // 记录根节点的深度（用于优化）
    int count;           // 记录连通分量的个数
    int rest;            // 记录多余的连接数
   public:
    UniSet(int n) : parent(n), rank(n), count(n), rest(0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        // 压缩方式：直接指向根节点
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void uni(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            // 按秩合并
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            count--;
        } else {
            rest++;
        }
    }
    int Count() { return count; }
    int Rest() { return rest; }
};

class Solution {
   public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UniSet us(n);
        for (auto& e : connections) {
            us.uni(e[0], e[1]);
        }
        if (us.Rest() < us.Count() - 1) return -1;
        return us.Count() - 1;
    }
};
// @lc code=end
