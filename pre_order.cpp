/*Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed.

* Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> my_return;
    TreeNode* curr_node = A;
    stack<TreeNode*> my_stack;
    
    if(A == NULL){
      return my_return;
    }
    
    do{
        if(curr_node == NULL){
            curr_node = my_stack.top();
            my_stack.pop();
            curr_node = curr_node->right;
            if(curr_node != NULL){
                my_return.push_back(curr_node->val);
                my_stack.push(curr_node);
                curr_node = curr_node->left;    
            }
            
        }
        else{
            my_return.push_back(curr_node->val);
            my_stack.push(curr_node);
            curr_node = curr_node->left;
        }
    }while(!my_stack.empty());
    
    return my_return;
    
}
