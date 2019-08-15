/*
 * @lc app=leetcode id=2 lang=golang
 *
 * [2] Add Two Numbers
 */

package leetcode

// @lc code=start
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{}
	p := head

	for carry := 0; p != nil; p = p.Next {
		if l1 != nil {
			p.Val += l1.Val
			l1 = l1.Next
		}

		if l2 != nil {
			p.Val += l2.Val
			l2 = l2.Next
		}

		if p.Val >= 10 {
			p.Val -= 10
			carry = 1
		} else {
			carry = 0
		}

		if l1 != nil || l2 != nil || carry != 0 {
			p.Next = &ListNode{Val: carry}
		}
	}

	return head
}

// @lc code=end
