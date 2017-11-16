/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int mymax(TreeNode* A, int maxi){
     if(A == NULL){
         return maxi;
     }
     maxi = max(mymax(A->left,maxi+1),mymax(A->right,maxi+1));
     return maxi;
 }
int Solution::maxDepth(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return mymax(A,0);
}
