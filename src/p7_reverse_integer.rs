/*
 * @lc app=leetcode id=7 lang=rust
 *
 * [7] Reverse Integer
 */
use super::Solution;

// @lc code=start
impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let negative = x < 0;
        let mut y = if negative { -x } else { x };
        let mut result = 0i32;
        while y > 0 {
            if let Some(r) = result.checked_mul(10).and_then(|r| r.checked_add(y % 10)) {
                result = r;
                y /= 10;
            } else {
                return 0;
            }
        }

        if negative {
            -result
        } else {
            result
        }
    }
}
// @lc code=end

#[test]
fn test() {
    assert_eq!(Solution::reverse(123), 321);
    assert_eq!(Solution::reverse(-321), -123);
    assert_eq!(Solution::reverse(120), 21);
}
