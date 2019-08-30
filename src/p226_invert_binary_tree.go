/*
 * @lc app=leetcode id=226 lang=golang
 *
 * [226] Invert Binary Tree
 */

package leetcode

// @lc code=start
func invertTree(root *TreeNode) *TreeNode {
	if root != nil {
		root.Left, root.Right = invertTree(root.Right), invertTree(root.Left)
	}
	return root
}

// @lc code=end
