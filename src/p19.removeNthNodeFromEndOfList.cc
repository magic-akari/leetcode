#include "structs.hh"

using namespace std;
/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    auto removeNthFromEnd(ListNode* head, int n) -> ListNode* {
        auto* end = head;
        auto* p = head;

        auto offset = n + 1;

        while (end != nullptr && --offset >= 0) {
            end = end->next;
        }

        while (end != nullptr) {
            p = p->next;
            end = end->next;
        }

        if (offset > 0) {
            return p->next;
        }

        p->next = p->next->next;
        return head;
    }
};
// @lc code=end

#include <iostream>

auto main() -> int {
    Solution s;

    cout << s.removeNthFromEnd(new ListNode{1, 2, 3, 4, 5}, 2) << endl;
    cout << s.removeNthFromEnd(new ListNode{1, 2}, 1) << endl;
    cout << s.removeNthFromEnd(new ListNode{1, 2}, 2) << endl;
    cout << s.removeNthFromEnd(new ListNode{1}, 1) << endl;
    return 0;
}
