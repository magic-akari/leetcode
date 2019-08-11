#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#

from structs import ListNode


# @lc code=start
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode(0)
        p = head
        carry = 0

        while p != None:
            if l1 != None:
                p.val += l1.val
                l1 = l1.next

            if l2 != None:
                p.val += l2.val
                l2 = l2.next

            if p.val >= 10:
                p.val -= 10
                carry = 1
            else:
                carry = 0

            if l1 != None or l2 != None or carry != 0:
                p.next = ListNode(carry)

            p = p.next

        return head


# @lc code=end

if __name__ == "__main__":
    s = Solution()
    l1 = ListNode(2)**ListNode(4)**ListNode(3)
    l2 = ListNode(5)**ListNode(6)**ListNode(4)

    print(s.addTwoNumbers(l1, l2))
