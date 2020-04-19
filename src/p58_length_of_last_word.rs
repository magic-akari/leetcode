/*
 * @lc app=leetcode id=58 lang=rust
 *
 * [58] Length of Last Word
 */

use super::Solution;

// @lc code=start
impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut length = 0;

        for c in s.chars().rev() {
            if c != ' ' {
                length += 1;
            } else if length > 0 {
                break;
            }
        }

        length
    }
}
// @lc code=end

#[test]
fn test() {
    assert_eq!(Solution::length_of_last_word("Hello World".to_owned()), 5)
}
