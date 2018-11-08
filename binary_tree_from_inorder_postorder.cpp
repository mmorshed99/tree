/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int search(vector<int> &in, int start, int end, int my_val){
    for(int i=start; i<=end; i++)
        if(in[i] == my_val)
            return i;
}

TreeNode* my_Tree(vector<int> &post, vector<int> &in, int start, int end, int &treeIndex){

    if(start > end)     // In: 7,5,6,2,3,1,4   Post: 5,6,3,1,4,2,7
        return NULL;

    TreeNode* node = new TreeNode(post[treeIndex--]);

    if(start == end)
        return node;

    int root = search(in, start, end, node->val);

    node->right = my_Tree(post, in, root+1, end, treeIndex);
    node->left = my_Tree(post, in, start, root-1, treeIndex);

    return node;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int tree_len = A.size()-1;
    return my_Tree(B, A, 0, tree_len, tree_len);
}
