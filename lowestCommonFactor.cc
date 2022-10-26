#include<bits/stdc++.h>
#include"BinaryTreeClass.cc"
using namespace std;
// taking input of binaryTree levelwise using queue
BinaryTreeNode<int> * takeInputLevelWise(){
    int data; 
    cout<<"Enter the root data"<<endl;
    cin>>data;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int> *>  pending;
    pending.push(root);
    while(pending.size()!=0){
        BinaryTreeNode<int> * front = pending.front();
        pending.pop();
        cout<<"Enter the data of left child of "<<front->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            BinaryTreeNode<int> * leftchild = new BinaryTreeNode<int>(leftdata);
            front->left = leftchild;
            pending.push(leftchild);
        }

        cout<<"Enter the data of right child of "<<front->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            BinaryTreeNode<int> * rightchild = new BinaryTreeNode<int>(rightdata);
            front->right = rightchild;
            pending.push(rightchild);
        }
    }
    return root;

}

BinaryTreeNode<int> * lca(BinaryTreeNode<int> * root ,int n1 ,int n2 ){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
     BinaryTreeNode<int> * left = lca(root->left,n1,n2);
     BinaryTreeNode<int> * right = lca(root->right,n1,n2);
     
     if(left!=NULL && right!=NULL){
         return root;
     }
     else if(left!=NULL && right == NULL){
         return left;
     }
     else if(left == NULL && right!=NULL){
         return right;
     }
     else{
         return NULL;
     }
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> * root = takeInputLevelWise();
    BinaryTreeNode<int> *ans = lca(root,8,9);
    cout<<ans->data;
}
