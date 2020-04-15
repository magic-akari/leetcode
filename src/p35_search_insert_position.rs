/*
 * @lc app=leetcode id=35 lang=rust
 *
 * [35] Search Insert Position
 */
use super::Solution;

// @lc code=start
impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let len = nums.len() as i32;
        let mut left = 0i32;
        let mut right = len;

        loop {
            if left > right || left == len {
                break left;
            }

            let center = (left + right) / 2;
            let value = nums[center as usize];
            if target == value {
                break center;
            }

            if target > value {
                left = center + 1;
            } else {
                right = center - 1;
            }
        }
    }
}
// @lc code=end

#[test]
fn test() {
    let nums1 = vec![1, 3, 5, 7];
    assert_eq!(Solution::search_insert(nums1.clone(), 0), 0);
    assert_eq!(Solution::search_insert(nums1.clone(), 1), 0);
    assert_eq!(Solution::search_insert(nums1.clone(), 2), 1);
    assert_eq!(Solution::search_insert(nums1.clone(), 3), 1);
    assert_eq!(Solution::search_insert(nums1.clone(), 4), 2);
    assert_eq!(Solution::search_insert(nums1.clone(), 5), 2);
    assert_eq!(Solution::search_insert(nums1.clone(), 6), 3);
    assert_eq!(Solution::search_insert(nums1.clone(), 7), 3);
    assert_eq!(Solution::search_insert(nums1.clone(), 8), 4);
}
