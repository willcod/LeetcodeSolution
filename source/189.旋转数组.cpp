/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        int count = 0;
        for (int i = 0; count < n; i++) {
            int current = i;
            int previous = nums[i];

            do {
                int next = (k+current) % n;
                int temp = nums[next];
                nums[next] = previous;
                previous = temp;

                current = next;
                count++;
            } while (current != i);
        }
    }
};
// @lc code=end

