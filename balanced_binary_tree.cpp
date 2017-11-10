/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int check_balanced(TreeNode* node){
    if(node == NULL) return 1;

    else if(node->left == NULL && node->right == NULL) return 1;


    else if(node->left != NULL && node->right != NULL) return (check_balanced(node->right) * check_balanced(node->left));
        
    
    else if(node->left == NULL){
        if(node->right != NULL){
           TreeNode* next = node->right;
           if(next->right != NULL || next->left != NULL){
              return 0;
            }
        }
            
        else return 1;
    }
    else if(node->right == NULL){
        if(node->left != NULL) {
           TreeNode* next = node->left;
          if(next->right != NULL || next->left != NULL){
              return 0;
            }
        }
        else return 1;
    }
    return 1;
}
 
int Solution::isBalanced(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return check_balanced(A);
}
