/*
 * @lc app=leetcode id=226 lang=java
 *
 * [226] Invert Binary Tree
 */

import structs.*;

class InvertBinaryTree {
    // @lc code=start
    class Solution {
        public TreeNode invertTree(TreeNode root) {
            if (root != null) {
                TreeNode left = root.left;
                TreeNode right = root.right;
                root.left = invertTree(right);
                root.right = invertTree(left);
            }

            return root;
        }
    }
    // @lc code=end

    public static void main(String[] args) {
        var input = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)),
                new TreeNode(7, new TreeNode(6), new TreeNode(9)));

        var output = (new InvertBinaryTree()).new Solution().invertTree(input);

        System.out.println(output.left.val == 7);

    }
}