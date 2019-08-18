/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 */

#include "structs.h"

// @lc code=start
typedef struct ListNode ListNode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));

    ListNode* p = head;
    for (int carry = 0; p != NULL; p = p->next) {
        p->val = carry;

        if (l1 != NULL) {
            p->val += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            p->val += l2->val;
            l2 = l2->next;
        }

        if (p->val >= 10) {
            p->val -= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        p->next = (l1 != NULL || l2 != NULL || carry != 0) ? (ListNode*)malloc(sizeof(ListNode)) : NULL;
    }

    return head;
}
// @lc code=end

int main(int argc, char const* argv[]) {
    ListNode* l1 = arrayToListNode((int[]){2, 4, 3}, 3);
    ListNode* l2 = arrayToListNode((int[]){5, 6, 4}, 3);
    ListNode* l3 = arrayToListNode((int[]){7, 0, 8}, 3);

    ListNode* actual = addTwoNumbers(l1, l2);

    printf("expected: \t");
    printListNode(l3);
    printf("\nactual: \t");
    printListNode(actual);
    puts("");

    freeListNode(l1);
    freeListNode(l2);
    freeListNode(l3);
    freeListNode(actual);

    return 0;
}
