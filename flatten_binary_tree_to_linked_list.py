# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param A : root node of tree
    # @return the root node in the tree
    def flatten(self, A):
        def preorderTraversal(A):
            if A == None:
                return A
            done = 0
            mystack = [A]
            prev = A
            curr = A.left
            while(done == 0):
                if curr != None:
                    mystack.append(curr)
                    prev = curr
                    curr = curr.left
                else:
                    if len(mystack) != 0:
                        curr = mystack[-1]
                        del mystack[-1]
                        curr = curr.right
                        if curr != None:
                            prev.left = curr
                    else:
                        done = 1
            return
        preorderTraversal(A)  ## put everything on left side while doing in order traversal
        curr = A
        while(curr != None):   # now put all left to right in one more travel
            curr.right = curr.left
            curr.left = None
            curr = curr.right
        return A
