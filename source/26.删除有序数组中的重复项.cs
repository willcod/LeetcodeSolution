/*
 * @lc app=leetcode.cn id=26 lang=csharp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
public class Solution {
    public int RemoveDuplicates(int[] nums) {
        if (nums == null || nums.Length == 0)
            return 0;

        int left = 0;
        for (int right = 1; right < nums.Length; right++) {
            if (nums[left] != nums[right]) {
                nums[++left] = nums[right];
            }
        }

        return ++left;
    }
}
// @lc code=end

