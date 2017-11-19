/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    vector<TreeLinkNode*> save;
    A-> next = NULL;
    if(A != NULL) {
        save.push_back(A);
    while(1){
        if(save.empty()) break;
        vector<TreeLinkNode*> temp;
        for(int i = 0; i<save.size(); i++){
            if (i != save.size()-1){
                save[i]->next = save[i+1];
            }
                if(save[i]->left != NULL) temp.push_back(save[i]->left);
                if(save[i]->right != NULL) temp.push_back(save[i]->right);            
        }
        save[save.size()-1]->next = NULL;
        save = temp;
    }
    }
}
