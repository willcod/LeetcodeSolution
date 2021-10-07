/*
 * @lc app=leetcode.cn id=434 lang=rust
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
impl Solution {
    pub fn count_segments(s: String) -> i32 {
        let mut count = 0;
        for i in 0..s.len() {
            if (s.chars().nth(i).unwrap() != ' ' 
                && (i == 0 || s.chars().nth(i-1).unwrap() == ' ')) {
                count += 1;
            }
        }
        return count;
    }
}
// @lc code=end

