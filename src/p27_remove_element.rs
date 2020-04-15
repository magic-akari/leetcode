/*
 * @lc app=leetcode id=27 lang=rust
 *
 * [27] Remove Element
 */
use super::Solution;

// @lc code=start
impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let len = nums.len();
        if len == 0 {
            return 0;
        }

        let mut left: usize = 0;
        let mut right: usize = len - 1;

        loop {
            while right > 0 && nums[right] == val {
                right -= 1;
            }

            while left < len && nums[left] != val {
                left += 1;
            }

            if left >= right {
                break;
            }

            nums.swap(left, right);
            right -= 1;
            left += 1;
        }

        left as i32
    }
}
// @lc code=end

#[test]
fn test() {
    let mut nums1 = vec![3, 2, 2, 3];
    assert_eq!(Solution::remove_element(&mut nums1, 3), 2);
    assert_eq!(&nums1[..2], &vec![2, 2][..]);

    let mut nums2 = vec![1];
    assert_eq!(Solution::remove_element(&mut nums2, 1), 0);

    let mut nums2 = vec![2];
    assert_eq!(Solution::remove_element(&mut nums2, 3), 1);
}
