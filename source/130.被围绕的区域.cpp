/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */
#include "cpp_includes.h"
// @lc code=start

class JointSet {
  public:
    JointSet(int n) : _count(n), _master(n, 0) {
        for (int i = 0; i < n; i++) {
            _master[i] = i;
        }
    }

    int find(int a) {
        while (_master[a] != a) {
            _master[a] = _master[_master[a]];
            a = _master[a];
        }

        return a;
    }

    int count() { return _count; }
    void joint(int a, int b) {
        int masterA = find(a);
        int masterB = find(b);

        if (masterA == masterB)
            return;

        _master[masterA] = masterB;
        _count--;
    }
    bool isConnected(int a, int b) {
        int masterA = find(a);
        int masterB = find(b);

        return masterA == masterB;
    }

  private:
    int _count;
    vector<int> _master;
};

class Solution {
  public:
    const vector<vector<int>> fourDir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty())
            return;

        int m = board.size();
        int n = board[0].size();

        JointSet js(n * m + 1);
        int dummy = n * m;

        auto node = [&](int i, int j) {
            return i * n + j;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O') {
                    if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                        js.joint(node(i, j), dummy);
                    } else {
                        // for (int d = 0; d < fourDir.size(); d++) {
                        //     int di = i + fourDir[d][0];
                        //     int dj = j + fourDir[d][1];
                        //     if (isValid(board, di, dj) &&
                        //         board[di][dj] == 'O') {
                        //         js.joint(node(i, j), node(di, dj));
                        //     }
                        // }
                        if (i - 1 > -1 && board[i - 1][j] == 'O')
                        js.joint(node(i, j), node(i - 1, j));
                    if (i + 1 < m && board[i + 1][j] == 'O')
                        js.joint(node(i, j), node(i + 1, j));
                    if (j - 1 > -1 && board[i][j - 1] == 'O')
                        js.joint(node(i, j), node(i, j - 1));
                    if (j + 1 < n && board[i][j + 1] == 'O')
                        js.joint(node(i, j), node(i, j + 1));

                    }
                }
            }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 'O' && !js.isConnected(node(i, j), dummy)) {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }

    bool isValid(vector<vector<char>> &board, int x, int y) {
        return x >= 1 && y >= 1 && x < board.size() - 1 &&
               y < board[0].size() - 1;
    }
};
// @lc code=end
