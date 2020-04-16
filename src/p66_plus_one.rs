/*
 * @lc app=leetcode id=66 lang=rust
 *
 * [66] Plus One
 */
use super::Solution;

// @lc code=start
impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut digits = digits;

        let mut carry = 1;
        for i in digits.iter_mut().rev() {
            *i += carry;
            if *i > 9 {
                *i -= 10;
                carry = 1;
            } else {
                carry = 0;
                break;
            }
        }

        if carry == 1 {
            digits.insert(0, 1)
        }

        digits
    }
}
// @lc code=end

#[test]
fn test() {
    assert_eq!(Solution::plus_one(vec![1, 2, 3]), vec![1, 2, 4]);
    assert_eq!(Solution::plus_one(vec![1, 2, 9]), vec![1, 3, 0]);
    assert_eq!(Solution::plus_one(vec![9, 9, 9]), vec![1, 0, 0, 0]);
}
