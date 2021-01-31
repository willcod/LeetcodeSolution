/*
 * @lc app=leetcode.cn id=839 lang=cpp
 *
 * [839] 相似字符串组
 */
#include "cpp_includes.h"
// @lc code=start
class UniFind {
   private:
    int count;
    vector<int> parent;

   public:
    UniFind(int n) : count(n), parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool isConnected(int x, int y) { return find(x) == find(y); }

    void join(int x, int y) {
        int px = parent[x];
        int py = parent[y];

        if (px == py) return;

        parent[px] = py;
        count--;
    }

    int getCount() { return count; }
};

class Solution {
   public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        UniFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (uf.isConnected(i, j)) continue;
                if (isSimilar(strs[i], strs[j])) {
                    uf.join(i, j);
                }
            }
        }
        return uf.getCount();
    }

    bool isSimilar(string s1, string s2) {
        if (s1.length() != s2.length()) return false;

        int diff = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) diff++;
            if (diff > 2) return false;
        }
        return true;
    }
};
// @lc code=end
