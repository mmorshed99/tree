#Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

#Example :
#
#    1
#   / \
#  2   2
# / \ / \
#3  4 4  3
#
#The above binary tree is symmetric.
#But the following is not:
#
#    1
#   / \
#  2   2
#   \   \
#   3    3
#
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param A : root node of tree
    # @return an integer
    def isSymmetric(self, A):
        def create_tree(node,old_node):
            if old_node == None:
                return
            if old_node.right != None:
                node_left = TreeNode(old_node.right.val)
                node.left = node_left
                create_tree(node.left,old_node.right)
            if old_node.left != None:
                node_right = TreeNode(old_node.left.val)
                node.right = node_right
                create_tree(node.right,old_node.left)
            return
        def is_identical(my_A,my_B):
            if my_A != None and my_B != None:
                if my_A.val == my_B.val:
                    return is_identical(my_A.left,my_B.left) * is_identical(my_A.right,my_B.right)
                else:
                    return 0
            elif my_A != None and my_B == None:
                return 0
            elif my_A == None and my_B != None:
                return 0
            else:
                return 1
        new_A = TreeNode(A.val)
        create_tree(new_A,A)
        return is_identical(new_A,A)
