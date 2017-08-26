 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
//Solution approach 1
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> my_return;
  TreeNode* curr_node = A;
  stack<TreeNode*> my_stack;
  TreeNode* temp;
  int down = 1;
  if (A == NULL){
    return my_return;
  }

  do{
    //std::cout<< my_return;  
    if (down == 1){
      if (curr_node != NULL){
        my_stack.push(curr_node);
        curr_node = curr_node->left;
      }
      else{
        down = 0;
      }
    }
    else if (down == 0){
      if(curr_node != NULL){
        temp = my_stack.top();
        if (temp->right == curr_node){
          my_return.push_back(temp->val);
          //std::cout<<temp->val;
          my_stack.pop();
          curr_node = temp;
          if(my_stack.empty()) return my_return;
                                     }
        else{
          curr_node = temp->right;
          down = 1;
            }
                             }
      else if(curr_node == NULL){
        temp = my_stack.top();
        if(temp->right == NULL)          {
          my_return.push_back(temp->val);
          //std::cout<<temp->val;
          //my_stack.pop();
          //if(my_stack.empty()) return my_return;
          curr_node = temp;
          my_stack.pop();
                                          }
       else                 {
          curr_node = temp->right;
          down = 1;
                            }

                                  }
                       }
  }while(!my_stack.empty());
  return my_return;

    
}

// Solution approach 2 
vector<int> Solution::postorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> my_return;
    TreeNode* curr_node = A;
    stack<TreeNode*> my_stack;
    TreeNode* temp;
    if (A == NULL){
        return my_return;
    }
    
    do{
        if(curr_node == NULL){
            temp = my_stack.top();
            curr_node = temp->right;
            if(curr_node == NULL){
                my_return.push_back(temp->val);
                my_stack.pop();
                if(my_stack.empty()){
                    return my_return;
                                    }
                curr_node = my_stack.top();
                while(curr_node->right == temp){
                    temp = curr_node;
                    my_return.push_back(curr_node->val);
                    my_stack.pop();
                    if(my_stack.empty()){
                        return my_return;
                                        }
                    curr_node = my_stack.top();
                                   }
                curr_node = curr_node->right;    
            }
        }
        else{
            my_stack.push(curr_node);
            curr_node = curr_node->left;
            }
    }while(!my_stack.empty());
    return my_return;
    
}
