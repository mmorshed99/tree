#Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
#
#    Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
#
#Example :
#
#
#Given A : [1, 2, 3]
#A height balanced BST  : 
#
#      2
#    /   \
#   1     3
#
#
# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param A : tuple of integers
    # @return the root node in the tree
    def sortedArrayToBST(self, A):
        def my_tree(A):
            if len(A) == 0:
                return None
            if len(A) == 3:
                root = TreeNode(A[1])
                left = TreeNode(A[0])
                right = TreeNode(A[2])
                root.left = left
                root.right = right
                return root
            if len(A) == 2:
                root = TreeNode(A[1])
                left = TreeNode(A[0])
                root.left = left
                return root
            if len(A) == 1:
                return TreeNode(A[0])
            left = my_tree(A[:len(A)/2])
            right = my_tree(A[(len(A)/2)+1:])
            root = TreeNode(A[len(A)/2])
            root.left = left
            root.right = right
            return root
        if len(A) == 0:
            return None
        return my_tree(A)
