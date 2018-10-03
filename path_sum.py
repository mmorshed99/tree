# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param A : root node of tree
    # @param B : integer
    # @return an integer
    def hasPathSum(self, A, B):
        def my_sum(root,curr_sum,B):
            curr_sum += root.val
            if root.left == None and root.right == None:
                if curr_sum == B:
                    return 1
                else:
                    return 0
            if root.left == None:
                return my_sum(root.right,curr_sum,B)
            if root.right == None:
                return my_sum(root.left,curr_sum,B)
            return (my_sum(root.right,curr_sum,B) or my_sum(root.left,curr_sum,B))
        if A == None:
            if B == 0:
                return 1
            else:
                return 0
        return my_sum(A,0,B)
