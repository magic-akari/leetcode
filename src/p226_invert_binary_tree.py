#
# @lc app=leetcode id=226 lang=python3
#
# [226] Invert Binary Tree
#

from structs import TreeNode


# @lc code=start
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if (root != None):
            root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)

        return root


# @lc code=end

if __name__ == "__main__":
    s = Solution()
    input = TreeNode(4, TreeNode(2, TreeNode(1), TreeNode(3)), TreeNode(7, TreeNode(6), TreeNode(9)))
    output = s.invertTree(input)

    print(output.left.left.val == 9)
    print(output.left.right.val == 6)
    print(output.right.left.val == 3)
    print(output.right.right.val == 1)
