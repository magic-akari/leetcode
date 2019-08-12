# frozen_string_literal: true

#
# @lc app=leetcode id=1 lang=ruby
#
# [1] Two Sum
#

# @lc code=start
# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
  record = {}

  nums.each_with_index do |num, i|
    return [record[num], i] if record.include?(num)

    record[target - num] = i
  end

  []
end
# @lc code=end

print(two_sum([2, 7, 11, 15], 9))
