# frozen_string_literal: true

#
# @lc app=leetcode id=2 lang=ruby
#
# [2] Add Two Numbers
#

require_relative 'structs.rb'

# @lc code=start
# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}
def add_two_numbers(l1, l2)
  head = ListNode.new(0)
  p = head
  carry = 0

  loop do
    unless l1.nil?
      p.val += l1.val
      l1 = l1.next
    end

    unless l2.nil?
      p.val += l2.val
      l2 = l2.next
    end

    if p.val >= 10
      p.val -= 10
      carry = 1
    else
      carry = 0
    end

    break if l1.nil? && l2.nil? && carry.zero?

    p = p.next = ListNode.new(carry)
  end

  head
end
# @lc code=end

l1 = ListNode.new(2)**ListNode.new(4)**ListNode.new(3)
l2 = ListNode.new(5)**ListNode.new(6)**ListNode.new(4)

puts(l1)
puts(l2)
puts(add_two_numbers(l1, l2))
