/*
 * @lc app=leetcode id=1 lang=golang
 *
 * [1] Two Sum
 */

package leetcode

// @lc code=start
func twoSum(nums []int, target int) []int {
	record := make(map[int]int)

	for i, num := range nums {
		if matched, ok := record[num]; ok {
			return []int{matched, i}
		}

		record[target-num] = i
	}
	return []int{}
}

// @lc code=end
