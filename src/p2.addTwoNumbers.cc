/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

#include "structs.h"

// @lc code=start
class Solution {
   public:
    auto addTwoNumbers(ListNode* l1, ListNode* l2) const -> ListNode* {
        auto head = new ListNode(0);
        auto p = head;
        for (int carry = 0; p != nullptr; p = p->next) {
            if (l1 != nullptr) {
                p->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                p->val += l2->val;
                l2 = l2->next;
            }

            if (p->val >= 10) {
                p->val -= 10;
                carry = 1;
            } else {
                carry = 0;
            }

            p->next = (l1 != nullptr || l2 != nullptr || carry != 0) ? new ListNode(carry) : nullptr;
        }

        return head;
    }
};
// @lc code=end

auto main(int argc, char const* argv[]) -> int {
    auto l1 = arrayToListNode((int[]){2, 4, 3}, 3);
    auto l2 = arrayToListNode((int[]){5, 6, 4}, 3);
    auto l3 = arrayToListNode((int[]){7, 0, 8}, 3);

    Solution s;

    auto actual = s.addTwoNumbers(l1, l2);

    printf("expected: \t");
    printListNode(l3);
    printf("\nactual: \t");
    printListNode(actual);
    puts("");

    return 0;
}
