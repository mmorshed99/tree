/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int max_idx(vector<int> &A, int start, int end){
     int max = A[start];
     int idx = start;
     for(int i = start+1; i<= end; i++){
         if (A[i]> max){
             max = A[i];
             idx = i;
         } 
     }
     return idx;
 }
 TreeNode* cart_tree(vector<int> &A, int start, int end){
     if(start>end) return NULL;
     int max = max_idx(A, start, end);
     TreeNode* x = new TreeNode(A[max]);
     x->right = cart_tree(A,max+1,end);
     x->left = cart_tree(A,start,max-1);
     return x;
 }
 TreeNode* Solution::buildTree(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
     return cart_tree(A,0,A.size()-1);
    
}
