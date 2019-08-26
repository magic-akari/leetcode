/*
 * @lc app=leetcode id=2 lang=javascript
 *
 * [2] Add Two Numbers
 */

import { ListNode } from "./structs.js";

// @lc code=start
/**
 * @param {ListNode | null} l1
 * @param {ListNode | null} l2
 * @return {ListNode | null}
 */
const addTwoNumbers = (l1, l2) => {
    let head = new ListNode(0);

    for (let p = /** @type {ListNode | null} */ (head), carry = 0; p != null; p = p.next) {
        if (l1 !== null) {
            p.val += l1.val;
            l1 = l1.next;
        }

        if (l2 !== null) {
            p.val += l2.val;
            l2 = l2.next;
        }

        if (p.val >= 10) {
            p.val -= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        p.next = l1 !== null || l2 !== null || carry !== 0 ? new ListNode(carry) : null;
    }

    return head;
};
// @lc code=end

console.log(
    addTwoNumbers(new ListNode(2, new ListNode(4, new ListNode(3))), new ListNode(5, new ListNode(6, new ListNode(4)))),
);
