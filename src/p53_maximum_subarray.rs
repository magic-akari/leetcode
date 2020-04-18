/*
 * @lc app=leetcode id=53 lang=rust
 *
 * [53] Maximum Subarray
 */
use super::Solution;

// @lc code=start
impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut dp = 0;
        let mut max = nums[0];

        for i in nums.iter() {
            dp = (dp + *i).max(*i);
            max = max.max(dp)
        }

        max
    }
}
// @lc code=end

#[test]
fn test() {
    assert_eq!(
        Solution::max_sub_array(vec![-2, 1, -3, 4, -1, 2, 1, -5, 4]),
        6
    )
}
