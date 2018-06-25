# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param A : root node of tree
    # @return a list of integers
    def inorderTraversal(self, A):
        if A == None:
            return []
        done = 0
        mystack = [A]
        curr = A.left
        my_return = []
        while(done == 0):
            if curr != None:
               mystack.append(curr)
               curr = curr.left
            else:
                if len(mystack) != 0:
                   curr = mystack[-1]
                   del mystack[-1]
                   my_return.append(curr.val)
                   curr = curr.right
                else:
                    done = 1
        return my_return
