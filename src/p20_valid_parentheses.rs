/*
 * @lc app=leetcode id=20 lang=rust
 *
 * [20] Valid Parentheses
 */
use super::Solution;

// @lc code=start
impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack: Vec<char> = vec![];

        for c in s.chars() {
            match c {
                ')' => {
                    if stack.pop() != Some('(') {
                        return false;
                    }
                }
                ']' => {
                    if stack.pop() != Some('[') {
                        return false;
                    }
                }
                '}' => {
                    if stack.pop() != Some('{') {
                        return false;
                    }
                }

                _ => stack.push(c),
            }
        }

        stack.len() == 0
    }
}
// @lc code=end

#[test]
fn test() {
    assert_eq!(Solution::is_valid("()".to_owned()), true);
    assert_eq!(Solution::is_valid("()[]{}".to_owned()), true);
    assert_eq!(Solution::is_valid("(]".to_owned()), false);
    assert_eq!(Solution::is_valid("([)]".to_owned()), false);
    assert_eq!(Solution::is_valid("{[]}".to_owned()), true);
}
