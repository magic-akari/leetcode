/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */

#include "structs.h"

// @lc code=start
class Solution {
   public:
    auto invertTree(TreeNode* root) const -> TreeNode* {
        if (root != nullptr) {
            auto left = root->left;
            auto right = root->right;
            root->left = invertTree(right);
            root->right = invertTree(left);
        }
        return root;
    }
};
// @lc code=end
