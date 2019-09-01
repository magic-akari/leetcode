# frozen_string_literal: true

#
# @lc app=leetcode id=226 lang=ruby
#
# [226] Invert Binary Tree
#

require_relative 'structs.rb'

# @lc code=start
# @param {TreeNode} root
# @return {TreeNode}
def invert_tree(root)
  unless root.nil?
    root.left, root.right = invert_tree(root.right), invert_tree(root.left)
  end

  root
end
# @lc code=end
