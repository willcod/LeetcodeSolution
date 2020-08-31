/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visit(n, false);

        int num = 0;
        Dfs(rooms, visit, num, 0);
        return num == n;
    }

    void Dfs(vector<vector<int>>& rooms, vector<int>& visit, int& num, int index) {
        visit[index] = true;
        num++;
        for (auto r : rooms[index]) {
            if (visit[r] == false) {
                Dfs(rooms, visit, num, r);
            }
        }
    }
};
// @lc code=end

