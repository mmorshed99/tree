# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param A : root node of tree
    # @return a list of integers
    def preorderTraversal(self, A):
        if A == None:
            return []
        done = 0
        mystack = [A]
        my_return = []
        my_return.append(A.val)
        curr = A.left
        while(done == 0):
            if curr != None:
               mystack.append(curr)
               my_return.append(curr.val)
               curr = curr.left
            else:
                if len(mystack) != 0:
                   curr = mystack[-1]
                   del mystack[-1]
                   curr = curr.right
                else:
                    done = 1
        return my_return
