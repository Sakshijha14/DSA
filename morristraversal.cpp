/**
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 * Problem Statement: Given a Binary Tree, implement Morris Inorder Traversal and return the array containing its inorder sequence.

Morris Inorder Traversal is a tree traversal algorithm aiming to achieve a space complexity of O(1) without recursion or an external data structure. 
The algorithm should efficiently visit each node in the binary tree in inorder sequence, printing or processing the node values as it traverses, without using a stack or recursion.


explaination: from last node go back to root.[leftrootright]
case 1:if left is null. print current i.e root() go to right
case 2:first before moving to right.in left rightmost is connected to current.
case 3:whenever came back to root. pls check leftmost is already connected to root exist then remove thread.
move right.
case 4:remove all threads nothing should be left.
*/
#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class Solution{
    public:

    vector<int> MorrisInorder(TreeNode* root){
        vector<int> inorder;// forming inorder traversal result

        TreeNode* curr=root;

        while(curr!=NULL){

            if(curr->left==NULL){
            inorder.push_back(curr->val);//use case 1  print root
            curr=curr->right;//move to right side 
            }

            else{
                //if left is not null. go to left extreme rightmost.
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    //curr.left.right not be equal to root
                    prev=prev->right;
                }
                //now find if prev.right is null then make link to root
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;//move to left.left
                }
                else{
                    //is link is established before hand then remove link and add node to inorder and move to right child of tree
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
                
            }
        }
        return inorder;
    }
};

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->left->right->right=new TreeNode(6);

    Solution output;
    vector<int> inorder=output.MorrisInorder(root);

    cout<<"Using Morris Inorder Traversal: ";
    for(int i=0;i<inorder.size();i++){
        cout<<inorder[i]<<" ";
    }
    cout<<endl;

    


    return 0;
}