//Implement Tree traversals : Inorder, preorder, postorder
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node * left;
        node *right;

    node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
node *buildtree(node *root){
    cout<<"Enter the element"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1) return NULL;
    cout<<"Enter the left child of parent"<<" "<<data<<endl;
    root->left=buildtree(root->left);
     cout<<"Enter the right child of parent"<<" "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}
void preordertraversal(node *root){
   if(root==NULL) return;
        cout<<root->data<<" ";
        preordertraversal(root->left);
        preordertraversal(root->right);
}
void inordertraversal(node *root){
  if(root==NULL) return;
         inordertraversal(root->left);
        cout<<root->data<<" ";
        inordertraversal(root->right);
}
void postordertraversal(node *root){
   if(root==NULL) return;
         postordertraversal(root->left);
         postordertraversal(root->right);
        cout<<root->data<<" ";
}

int main(){
   
    node *root=NULL;
    root=buildtree(root);
    //1 2 -1 8 9 -1 10 -1 -1 -1 3 4 -1 -1 5 6 -1 -1 7 -1 -1
    cout<<"Inorder traversal is: "<<endl;
   inordertraversal(root);
    cout<<endl;
     cout<<"Preorder traversal is: "<<endl;
  preordertraversal(root);
     cout<<endl;
      cout<<"Postorder traversal is: "<<endl;
    postordertraversal(root);
   
}