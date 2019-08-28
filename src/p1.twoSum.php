<?php
/*
 * @lc app=leetcode id=1 lang=php
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target)
    {
        $record = [];

        foreach ($nums as $i => $num) {
            if (array_key_exists($num, $record)) {
                return [$record[$num], $i];
            }

            $record[$target - $num] = $i;
        }

        return [];
    }
}
// @lc code=end


echo json_encode((new Solution())->twoSum([2, 7, 11, 15], 9));
