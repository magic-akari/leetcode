/*
 * @lc app=leetcode id=226 lang=c
 *
 * [226] Invert Binary Tree
 */

#include "structs.h"

// @lc code=start
typedef struct TreeNode TreeNode;

struct TreeNode* invertTree(struct TreeNode* root) {
    if (root != NULL) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
    }
    return root;
}
// @lc code=end

int main(int argc, char const* argv[]) {
    TreeNode* input = &(TreeNode){
        .val = 4,
        .left =
            &(TreeNode){
                .val = 2,
                .left = &(TreeNode){.val = 1, .left = NULL, .right = NULL},
                .right = &(TreeNode){.val = 3, .left = NULL, .right = NULL},
            },
        .right =
            &(TreeNode){
                .val = 7,
                .left = &(TreeNode){.val = 6, .left = NULL, .right = NULL},
                .right = &(TreeNode){.val = 9, .left = NULL, .right = NULL},
            },
    };

    TreeNode* expected = &(TreeNode){
        .val = 4,
        .right =
            &(TreeNode){
                .val = 2,
                .right = &(TreeNode){.val = 1, .right = NULL, .left = NULL},
                .left = &(TreeNode){.val = 3, .right = NULL, .left = NULL},
            },
        .left =
            &(TreeNode){
                .val = 7,
                .right = &(TreeNode){.val = 6, .right = NULL, .left = NULL},
                .left = &(TreeNode){.val = 9, .right = NULL, .left = NULL},
            },
    };

    printf("%s", isSameTree(invertTree(input), expected) ? "true" : "false");

    return 0;
}
