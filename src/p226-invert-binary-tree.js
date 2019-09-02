/*
 * @lc app=leetcode id=226 lang=javascript
 *
 * [226] Invert Binary Tree
 */

import { TreeNode } from "./structs.js";

// @lc code=start
/**
 * @param {TreeNode | null} root
 * @return {TreeNode | null}
 */
const invertTree = (root) => {
    if (root !== null) {
        const { left, right } = root;
        root.left = invertTree(right);
        root.right = invertTree(left);
    }

    return root;
};
// @lc code=end
