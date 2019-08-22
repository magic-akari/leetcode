
/*
 * @lc app=leetcode id=2 lang=java
 *
 * [2] Add Two Numbers
 */

import structs.ListNode;

class AddTwoNumbers {
    // @lc code=start
    class Solution {
        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode head = new ListNode(0);
            ListNode p = head;

            for (int carry = 0; p != null; p = p.next) {
                if (l1 != null) {
                    p.val += l1.val;
                    l1 = l1.next;
                }
                if (l2 != null) {
                    p.val += l2.val;
                    l2 = l2.next;
                }

                if (p.val >= 10) {
                    p.val -= 10;
                    carry = 1;
                } else {
                    carry = 0;
                }

                p.next = (l1 != null || l2 != null || carry != 0) ? new ListNode(carry) : null;
            }

            return head;
        }
    }
    // @lc code=end

    public static void main(String[] args) {
        var l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
        var l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
        var l3 = new ListNode(7, new ListNode(0, new ListNode(8)));

        var s = (new AddTwoNumbers()).new Solution();
        var actual = s.addTwoNumbers(l1, l2);
        System.out.println("expected: " + l3);
        System.out.println("actual: " + actual);
    }
}
