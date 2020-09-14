/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    int orgColor = image[sr][sc];
    if (orgColor != newColor) {
      flood(image, sr, sc, newColor, orgColor);
    }

    return image;
  }

  void flood(vector<vector<int>>& image, int x, int y, int newColor,
             int orgColor) {
    if (!isValid(image, x, y)) return;

    if (image[x][y] == orgColor) {
      image[x][y] = newColor;

      flood(image, x + 1, y, newColor, orgColor);
      flood(image, x - 1, y, newColor, orgColor);
      flood(image, x, y + 1, newColor, orgColor);
      flood(image, x, y - 1, newColor, orgColor);
    }
  }

  bool isValid(vector<vector<int>>& image, int x, int y) {
    return x >= 0 && y >= 0 && x < image.size() && y < image[0].size();
  }
};
// @lc code=end
