#ifndef LEETCODE_STRUCTS_H
#define LEETCODE_STRUCTS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    struct ListNode* next;
#ifdef __cplusplus
    ListNode(int val = 0, struct ListNode* next = NULL) : val(val), next(next) {}
#endif
} ListNode;

void freeListNode(ListNode* head) {
    for (ListNode* p = head; p != NULL;) {
        ListNode* next = p->next;
        free(p);
        p = next;
    }
}

bool isSameList(ListNode* p, ListNode* q) {
    if (p == NULL || q == NULL) {
        return p == q;
    }

    return p->val == q->val && isSameList(p->next, q->next);
}

void printListNode(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->next) {
        printf("%d -> ", p->val);
    }
    printf("NULL");
}

ListNode* arrayToListNode(int array[], int arraySize) {
    if (arraySize <= 0) {
        return NULL;
    }

    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* p = head;
    for (int i = 0; p != NULL;) {
        p->val = array[i];
        p = p->next = ++i < arraySize ? (ListNode*)malloc(sizeof(ListNode)) : NULL;
    }

    return head;
}

// Definition for a binary tree ListNode.
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
#ifdef __cplusplus
    TreeNode(int val = 0, struct TreeNode* left = NULL, struct TreeNode* right = NULL)
        : val(val), left(left), right(right) {}
#endif
} TreeNode;

void freeTreeNode(TreeNode* head) {
    if (head != NULL) {
        TreeNode* left = head->left;
        TreeNode* right = head->right;
        free(head);
        freeTreeNode(left);
        freeTreeNode(right);
    }
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL || q == NULL) {
        return p == q;
    }
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

#endif
