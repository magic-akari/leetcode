#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

from typing import List


# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        record = {}

        for (i, num) in enumerate(nums):
            matched = record.get(num)
            if matched != None:
                return [matched, i]

            record[target - num] = i


# @lc code=end

if __name__ == "__main__":
    s = Solution()
    print(s.twoSum([2, 7, 11, 15], 9))
