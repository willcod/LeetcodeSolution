/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    if (!isValid(image, sr, sc)) return image;
    int orgColor = image[sr][sc];
    if (orgColor != newColor) {
      Dfs(image, sr, sc, newColor, orgColor);
    }

    return image;
  }

  void Dfs(vector<vector<int>>& image, int x, int y, int newColor,
           int orgColor) {
    if (!isValid(image, x, y)) return;

    if (image[x][y] == orgColor) {
      image[x][y] = newColor;

      Dfs(image, x - 1, y, newColor, orgColor);
      Dfs(image, x + 1, y, newColor, orgColor);
      Dfs(image, x, y - 1, newColor, orgColor);
      Dfs(image, x, y + 1, newColor, orgColor);
    }
  }

  bool isValid(vector<vector<int>>& image, int x, int y) {
    return x >= 0 && x < image.size() && y >= 0 && y < image[0].size();
  }
};
// @lc code=end
