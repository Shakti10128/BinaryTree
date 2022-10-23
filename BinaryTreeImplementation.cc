#include<bits/stdc++.h>
#include"BinaryTreeClass.cc"
using namespace std;

// taking input of binarytree by recursion
BinaryTreeNode<int> * takeInput(){
    cout<<"enter the root data "<<endl;
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(data);

    cout<<"enter the data of left child "<<data<<endl;
    root->left = takeInput();
    cout<<"enter the data of right child "<<data<<endl;
    root->right = takeInput();
    return root;
}

// taking input of binaryTree by levelwise using queue
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

// for printing the binaryTree
void print(BinaryTreeNode<int> * root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

// printing levelwise
void printLevelWise(BinaryTreeNode<int> * root){
    queue<BinaryTreeNode<int> *>  p;
    p.push(root);
    while(p.size()!=0){
        BinaryTreeNode<int>* front = p.front();
        p.pop();
        cout<<front->data<<" ";
        if(front->left!=NULL){
            p.push(front->left);
        }
        if(front->right!=NULL){
            p.push(front->right);
        }
    }
}
int main(){
    // taking input using recursion
    // BinaryTreeNode<int> * root = takeInput();

    BinaryTreeNode<int> * root = takeInputLevelWise();
    printLevelWise(root);
}
