/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

TreeLinkNode* find_next(TreeLinkNode* curr){
    while(1){
    if(curr->next == NULL){
        return NULL;
    }
    curr = curr->next;
    if(curr->left != NULL || curr->right != NULL){
        return curr;
    }
    }
}

TreeLinkNode* find_next_parent(TreeLinkNode* curr){
    while(1){
        if(curr->left != NULL) return curr->left;
        if(curr->right != NULL) return curr->right;
        curr = curr->next;
        if(curr == NULL) return NULL;
    }
}

void Solution::connect(TreeLinkNode* A) {
    if(A==NULL){
        return;
    }
    TreeLinkNode* left_most_parent = A;
    TreeLinkNode* current = A;
    while(1){
        if(current->left != NULL){
            if(current->right != NULL)         {
                current->left->next = current->right;
                TreeLinkNode* next_right = find_next(current);
                if(next_right == NULL){
                    current = find_next_parent(left_most_parent);
                    left_most_parent = current;
                    if(left_most_parent == NULL) break;
                    
                                       }
                else{
                    if(next_right ->left != NULL)  {
                        current->right->next = next_right->left;
                        current = next_right;   
                                                   }
                    else {
                        current->right->next = next_right->right;
                        current = next_right;   
                         }
                    }
                                                } 

            else{
                TreeLinkNode* next_right = find_next(current);
                if(next_right == NULL){
                    current = find_next_parent(left_most_parent);
                    left_most_parent = current;
                    if(left_most_parent == NULL) break;
                                      }
                else{
                    if(next_right ->left != NULL){ 
                    current->left->next = next_right->left;
                    current = next_right;   
                                                 }
                    else{ 
                    current->left->next = next_right->right;
                    current = next_right; 
                        }
                    }
                }
                                  }
        else if(current->right != NULL){
            TreeLinkNode* next_right = find_next(current);
            if(next_right == NULL){
                    current = find_next_parent(left_most_parent);
                    left_most_parent = current;
                    if(left_most_parent == NULL) break;
                }
            else{
                if(next_right ->left != NULL) {
                current->right->next = next_right->left;
                current = next_right;  
                }
                else{ 
                current->right->next = next_right->right;
                current = next_right; 
                }
            }
        } 
        else{
            current = current->next;
            if(current == NULL){
                break;
            }
        }
    }
}
