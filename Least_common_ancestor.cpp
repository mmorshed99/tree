/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 vector<int> upper_nodes(TreeNode* root, vector<int> mylist, int target){
     vector<int> temp;
     if (root == NULL) return temp;
     mylist.push_back(root->val);
     if (root->val == target){
         return mylist;
     }
     vector<int> mylist1 = upper_nodes(root->left,mylist,target);
     vector<int> mylist2 = upper_nodes(root->right,mylist,target);
     if (mylist1.empty() && mylist2.empty()) return mylist1;
     else if (mylist1.empty()) return mylist2;
     else return mylist1;
     
 } 
 int Solution::lca(TreeNode* A, int val1, int val2) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> temp1;
    vector<int> temp2;
    temp1 = upper_nodes(A,temp1,val1);
    temp2 = upper_nodes(A,temp2,val2);
    if(temp1.empty() || temp2.empty()) return -1;
    for(int i =0; i<temp1.size();i++){
        if(val2 == temp1[i]) return val2;
    }
    for(int i =0; i<temp2.size();i++){
        if(val1 == temp2[i]) return val1;
    }
    for(int i =temp1.size()-1; i>=0;i--){
        for(int j =temp2.size()-1;j>=0;j--){
            if(temp1[i] == temp2[j]) return temp2[j];
        }
    }
}
