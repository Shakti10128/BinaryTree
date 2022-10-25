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


pair<int,int> solve(BinaryTreeNode<int> * root){
    pair<int,int> ans;
    if(root == NULL){
        return ans;
    }
    
    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);
    
    int h1 = left.second;
    
    int h2 = right.second;
    
    if(h1 == h2){
        ans.first = max(left.first,right.first) + root->data;
        ans.second = h1+1;
    }
    else if(h1>h2){
        ans.first = left.first + root->data;
        ans.second = h1+1;
    }
    else{
        ans.first = right.first + root->data;
        ans.second = h2+1;
    }
    return ans;
        
 }
    
int sumOfLongRootToLeafPath(BinaryTreeNode<int> *root){
    return solve(root).first;
}


// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> * root = takeInputLevelWise();
    int ans = sumOfLongRootToLeafPath(root);
    cout<<"longest path in BinaryTree "<<ans<<endl;
}
