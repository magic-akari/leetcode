/*
 * @lc app=leetcode id=26 lang=rust
 *
 * [26] Remove Duplicates from Sorted Array
 */
use super::Solution;

// @lc code=start
impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let len = nums.len();
        if len <= 1 {
            return len as i32;
        }

        let mut slow: usize = 0;
        let mut fast: usize = 1;

        while fast < len {
            if nums[slow] == nums[fast] {
                fast += 1;
                continue;
            }

            slow += 1;
            nums[slow] = nums[fast];
            fast += 1;
        }

        (slow + 1) as i32
    }
}
// @lc code=end

#[test]
fn test() {
    let mut nums1 = vec![1, 1, 2];
    assert_eq!(Solution::remove_duplicates(&mut nums1), 2);
    assert_eq!(
        nums1
            .iter()
            .take(2)
            .zip((vec![1, 2]).iter())
            .all(|(a, b)| a == b),
        true
    );

    let mut nums2 = vec![0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
    assert_eq!(Solution::remove_duplicates(&mut nums2), 5);
    assert_eq!(
        nums2
            .iter()
            .take(5)
            .zip((vec![0, 1, 2, 3, 4]).iter())
            .all(|(a, b)| a == b),
        true
    );
}
