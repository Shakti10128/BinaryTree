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

void solve(BinaryTreeNode<int> * root,int k,int &count,vector<int> ans){
    if(root==NULL){
        return;
    }
    ans.push_back(root->data);
    solve(root->left,k,count,ans);
    solve(root->right,k,count,ans);
    
    int size = ans.size();
    int sum = 0;
    for(int i = size-1;i>=0;i--){
        sum += ans[i];
        if(sum == k){
            count++;
        }
    }
        ans.pop_back();
}
int sumK(BinaryTreeNode<int> *root,int k){
    if(root == NULL){
        return 0;
    }
    vector<int> ans;
    int count = 0;
    solve(root,k,count,ans);
    return count;
}


// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> * root = takeInputLevelWise();
    int ans = sumK(root,3);
    cout<<ans;
}
