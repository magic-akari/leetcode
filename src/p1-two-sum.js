/*
 * @lc app=leetcode id=1 lang=javascript
 *
 * [1] Two Sum
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
const twoSum = (nums, target) => {
    /** @type {Map<number, number>} */
    const record = new Map();

    for (let i = 0; i < nums.length; ++i) {
        const num = nums[i];
        const last = record.get(num);
        if (last !== undefined) {
            return [last, i];
        } else {
            record.set(target - num, i);
        }
    }
    return [];
};
// @lc code=end

console.log(twoSum([2, 7, 11, 15], 9));
