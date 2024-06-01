/**Given a Binary Tree, design an algorithm to serialise and deserialise it. 
 * There is no restriction on how the serialisation and deserialization takes place. 
 * But it needs to be ensured that the serialised binary tree can be deserialized to the original tree structure.
 *  Serialisation is the process of translating a data structure or object state into a format that can be stored or transmitted (for example, across a computer network) and reconstructed later. 
 * The opposite operation, that is, extracting a data structure from stored information, is deserialization.
 * Example: input root=[1,2,3,null,null,4,5]
 *          output root=[1,2,3,null,null,4,5] */



#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

void inorder(TreeNode* root){
    if(root==NULL)
    return ;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
    

}

class Solution{
    public:

    string treetostring(TreeNode* root){

        if(root==NULL)
        return "";//if tree is empty

        string outputstring="";
        queue<TreeNode*>q;
        q.push(root);//inout root node

        while(!q.empty()){
            TreeNode* currentnode=q.front();
            q.pop();//pop out element present in queue front

            //now check the value of element 
            if(currentnode==nullptr){
                outputstring+="null,";   //if null add to string  'null,'
            }
            else{
                outputstring+=to_string(currentnode->val)+",";

                q.push(currentnode->left);//push the left and right children to queue for further
                q.push(currentnode->right);
            }
        }

        return outputstring;

    }

    TreeNode* stringtotree(string data){

        if(data.empty())
        return nullptr;

        stringstream  outputstring(data);
        string str;

        //reading root value from treetostring data
        getline(outputstring,str,',');
        TreeNode* root=new TreeNode(stoi(str));//stoi turns string to integer



        //using queue for traversal
        queue<TreeNode*>q;
        q.push(root); 

        //reconsturcting tree
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            //now reading value of left from treetostring data
            getline(outputstring,str,',');
            //if value is not null push to queue

            if(str!="null"){
                TreeNode* leftNode=new TreeNode(stoi(str));
                node->left=leftNode;
                q.push(leftNode);
            }
            getline(outputstring,str,',');
                if(str!="null"){
                    TreeNode* rightNode=new TreeNode(stoi(str));
                    node->right=rightNode;
                    q.push(rightNode);
                }
            }
            return root;

            }
        };

    





int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(5);

    Solution solution;
    cout<<"original tree: ";
    inorder(root);
    cout<<endl;

    string serialized=solution.treetostring(root);
    cout<<"Serialized: "<<serialized<<endl;

    TreeNode* deserialized=solution.stringtotree(serialized);
    cout<<"Tree after deserialized: ";
    inorder(deserialized);
    cout<<endl;

    


    return 0;
}