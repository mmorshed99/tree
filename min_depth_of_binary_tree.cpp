/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int mymin(TreeNode* A, int maxi){
     if(A == NULL){
         return maxi;
     }
     else if(A->left != NULL && A->right == NULL){
         maxi = mymin(A->left,maxi+1);
     }
     else if(A->left == NULL && A->right != NULL){
         maxi = mymin(A->right,maxi+1);
     }
     else{
         maxi = min(mymin(A->left,maxi+1),mymin(A->right,maxi+1));
     }
     return maxi;
 }
int Solution::minDepth(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return mymin(A,0);
}
