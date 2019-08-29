/*
 * @lc app=leetcode id=1 lang=kotlin
 *
 * [1] Two Sum
 */
import java.util.Arrays

// @lc code=start
class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val record = mutableMapOf<Int, Int>()

        for ((i, num) in nums.withIndex()) {
            when (val matched = record[num]) {
                is Int -> return intArrayOf(matched, i)
                else -> record[target - num] = i
            }
        }

        return IntArray(0)
    }
}
// @lc code=end

fun main() {
    val s = Solution()
    val result = s.twoSum(intArrayOf(2, 7, 11, 15), 9)
    println(Arrays.toString(result))
}
