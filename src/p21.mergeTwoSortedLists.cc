/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

#include "structs.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    auto mergeTwoLists(ListNode* l1, ListNode* l2) -> ListNode* {
        auto head = new ListNode(0);
        auto p = head;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        if (l1 != nullptr) {
            p->next = l1;
        }

        if (l2 != nullptr) {
            p->next = l2;
        }

        return head->next;
    }
};
// @lc code=end

auto main(int argc, char const* argv[]) -> int {
    auto l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    auto l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    auto l3 = (new Solution())->mergeTwoLists(l1, l2);

    printListNode(l3);
    return 0;
}
