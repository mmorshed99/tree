#Given an inorder traversal of a cartesian tree, construct the tree.
#
# Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
# Note: You may assume that duplicates do not exist in the tree. 
#Example :
#
#Input : [1 2 3]
#
#Return :   
#          3
#         /
#        2
#       /
#      1
#
# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param A : list of integers
    # @return the root node in the tree
    def buildTree(self, A):
        def create_tree(node,idx,A):
            if idx > 0:
                left_val = max(A[:idx])
                left_idx = A[:idx].index(left_val)
                left_node = TreeNode(left_val)
                node.left = left_node
                create_tree(left_node,left_idx,A[:idx])
            if idx < len(A) - 1:
                right_val = max(A[idx+1:])
                right_idx = A[idx+1:].index(right_val)
                right_node = TreeNode(right_val)
                node.right = right_node
                create_tree(right_node,right_idx,A[idx+1:])
            return
        if len(A) == 0:
            return TreeNode(0)
        my_root_val = max(A)
        root_idx = A.index(my_root_val)
        my_root = TreeNode(my_root_val)
        create_tree(my_root,root_idx,A)
        return my_root
