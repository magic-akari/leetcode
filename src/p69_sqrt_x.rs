/*
 * @lc app=leetcode id=69 lang=rust
 *
 * [69] Sqrt(x)
 */

use super::Solution;

// @lc code=start
impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        let x = x as i64;
        let mut result = x;

        while result * result > x {
            result = (result + x / result) / 2;
        }

        result as i32
    }
}
// @lc code=end

#[test]
fn test() {
    assert_eq!(Solution::my_sqrt(1), 1);
    assert_eq!(Solution::my_sqrt(2), 1);
    assert_eq!(Solution::my_sqrt(3), 1);
    assert_eq!(Solution::my_sqrt(4), 2);
    assert_eq!(Solution::my_sqrt(9), 3);
    assert_eq!(Solution::my_sqrt(10), 3);
    assert_eq!(Solution::my_sqrt(15), 3);
    assert_eq!(Solution::my_sqrt(2147395599), 46339);
}
