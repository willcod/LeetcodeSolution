/*
 * @lc app=leetcode.cn id=1579 lang=cpp
 *
 * [1579] 保证图可完全遍历
 */
#include "cpp_includes.h"
// @lc code=start
class UniFind {
   private:
    vector<int> parent;
    int count;

   public:
    UniFind(int n) : count(n), parent(n + 1) {
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool join(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return false;

        parent[px] = py;
        count--;
        return true;
    }

    bool isUnited() { return count == 1; }
};

class Solution {
   public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
        UniFind alice(n), bob(n);
        int res = 0;
        // Sort edges by their type such that all type 3 edges will be at the
        // beginning.
        sort(edges.begin(), edges.end(),
             [](vector<int> &a, vector<int> &b) { return a[0] > b[0]; });

        int edgesAdded = 0;

        for (auto &edge : edges) {  // For each edge -
            int type = edge[0], one = edge[1], two = edge[2];
            switch (type) {
                case 3:
                    edgesAdded += (bob.join(one, two) | alice.join(one, two));
                    break;
                case 2:
                    edgesAdded += bob.join(one, two);
                    break;
                case 1:
                    edgesAdded += alice.join(one, two);
                    break;
            }
        }

        return (bob.isUnited() && alice.isUnited())
                   ? (edges.size() - edgesAdded)
                   : -1;
    }
};
// @lc code=end
