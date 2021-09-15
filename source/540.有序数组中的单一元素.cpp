/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */
#include "cpp_includes.h"
/*
14/14 cases passed (8 ms)
Your runtime beats 86.9 % of cpp submissions
Your memory usage beats 85.04 % of cpp submissions (10.7 MB)
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i+=2) {
            if (nums[i] != nums[i+1]) {
                return nums[i];
            }
        }
        return nums.back();
    }
};

/*
14/14 cases passed (8 ms)
Your runtime beats 86.9 % of cpp submissions
Your memory usage beats 73.58 % of cpp submissions (10.8 MB)

奇数长度的数组首尾元素索引都为偶数，因此我们可以将 lo 和 hi 设置为数组首尾。
我们需要确保 mid 是偶数，如果为奇数，则将其减 1。
然后，我们检查 mid 的元素是否与其后面的索引相同。
如果相同，则我们知道 mid 不是单个元素。且单个元素在 mid 之后。则我们将 lo 设置为 mid + 2。
如果不是，则我们知道单个元素位于 mid，或者在 mid 之前。我们将 hi 设置为 mid。
一旦 lo == hi，则当前搜索空间为 1 个元素，那么该元素为单个元素，我们将返回它。

作者：LeetCode
链接：https://leetcode-cn.com/problems/single-element-in-a-sorted-array/solution/you-xu-shu-zu-zhong-de-dan-yi-yuan-su-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (mid % 2 == 1) mid--;
            if (nums[mid] == nums[mid+1]) {
                left = mid+2;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

    }
};
// @lc code=end

