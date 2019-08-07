# Definition for singly-linked list.
class ListNode:
    def __init__(self, val, next: 'ListNode' = None):
        self.val = val
        self.next = next

    def __pow__(self, other: 'ListNode'):
        self.next = other
        return self

    def __str__(self):
        return f"{self.val} -> {self.next}"

    def __eq__(self, other):
        if isinstance(other, self.__class__):
            return self.val == other.val and self.next == other.next
        else:
            return False


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val, left: 'TreeNode' = None, right: 'TreeNode' = None):
        self.val = val
        self.left = left
        self.right = right

    def __eq__(self, other):
        if isinstance(other, self.__class__):
            return self.val == other.val and self.left == other.left and self.right == other.right
        else:
            return False
