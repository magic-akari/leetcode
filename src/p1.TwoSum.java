/*
 * @lc app=leetcode id=1 lang=java
 *
 * [1] Two Sum
 */

import java.util.*;

class TwoSum {
    // @lc code=start
    class Solution {
        public int[] twoSum(int[] nums, int target) {
            HashMap<Integer, Integer> record = new HashMap<>();
            for (int i = 0; i < nums.length; ++i) {
                int num = nums[i];

                if (record.containsKey(num)) {
                    return new int[] { record.get(num), i };
                } else {
                    record.put(target - num, i);
                }
            }

            return new int[] {};
        }
    }
    // @lc code=end

    public static void main(String[] args) {
        var s = (new TwoSum()).new Solution();
        var result = s.twoSum(new int[] { 2, 7, 11, 15 }, 9);
        System.out.println(Arrays.toString(result));
    }

}
