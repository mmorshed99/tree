# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param A : root node of tree
    # @param B : integer
    # @return a list of list of integers
    def pathSum(self, A, B):
        def my_sum(root,curr_sum,B,my_ret,my_stack):
            curr_sum += root.val
            my_stack.append(root.val)
            if root.left == None and root.right == None:
                if curr_sum == B:
                    my_ret.append(my_stack)
                return my_ret
            my_stack1 = my_stack[:]
            my_stack2 = my_stack[:]
            if root.left != None:
                my_ret = my_sum(root.left,curr_sum,B,my_ret,my_stack1)
            if root.right != None:
                my_ret = my_sum(root.right,curr_sum,B,my_ret,my_stack2)
            return my_ret
        my_ret = []
        if A == None:
            return []
        return my_sum(A,0,B,my_ret,[])
