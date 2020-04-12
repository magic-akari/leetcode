/*
 * @lc app=leetcode id=9 lang=rust
 *
 * [9] Palindrome Number
 */
use super::Solution;

// @lc code=start
impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }

        let mut y = x;
        let mut result = 0i32;
        while y > 0 {
            if let Some(r) = result.checked_mul(10).and_then(|r| r.checked_add(y % 10)) {
                result = r;
                y /= 10;
            } else {
                return false;
            }
        }

        x == result
    }
}
// @lc code=end

#[test]
fn test() {
    assert_eq!(Solution::is_palindrome(121), true);
    assert_eq!(Solution::is_palindrome(-321), false);
    assert_eq!(Solution::is_palindrome(10), false);
}
