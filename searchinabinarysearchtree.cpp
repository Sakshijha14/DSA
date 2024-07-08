#include<bits/stdc++.h>
using namespace std;

struct TreeNode{

    int val;

    TreeNode*left;
    TreeNode*right;

    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{

    public:
    TreeNode* searchBST(TreeNode*root,int val){
        while(root!=NULL && root->val!=val){
            root=val<root->val?root->left:root->right;
            
        }
        return root;


    }
};

void printInorder(TreeNode*root){
    if(root==nullptr){
        return;
    }
    printInorder(root->left);
    cout<<root->val<<" ";

    printInorder(root->right);

}

int main(){

    TreeNode*root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(10);


    cout<<"Binary Search Tree: "<<endl;
    printInorder(root);

    Solution solution;

    int target=6;
    TreeNode* result=solution.searchBST(root,target);

    if(result!=nullptr){
        cout<<"value"<<target<<"found in BST"<<endl;
    }
    else{
        cout<<"value"<<target<<"not found in the BST"<<endl;
    }


    return 0;
}