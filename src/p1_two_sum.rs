/*
 * @lc app=leetcode id=1 lang=rust
 *
 * [1] Two Sum
 */

use super::Solution;

// @lc code=start
use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map: HashMap<i32, i32> = HashMap::new();
        for (i, v) in nums.iter().enumerate() {
            match map.get(v) {
                Some(&index) => return vec![index, i as i32],
                None => {
                    map.insert(target - v, i as i32);
                }
            }
        }
        vec![]
    }
}
// @lc code=end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        assert_eq!(vec![0, 1], Solution::two_sum(vec![2, 7, 11, 15], 9));
    }
}
