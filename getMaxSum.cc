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


/*---------------------------------------Question Description------------------------------------*/
/*
Maximum sum of Non-adjacent nodes.
MediumAccuracy: 55.35%Submissions: 35626Points: 4

Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.


Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.

*/


pair<int,int> solve(BinaryTreeNode<int> * root){
    if(root == NULL){
        pair<int,int> ans = make_pair(0,0);
        return ans;
    }
    
    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);
    
    pair<int,int> ans;
    ans.first = root->data + left.second + right.second;
    ans.second = max(left.first,left.second) + max(right.first,right.second);
    return ans;
}

int getMaxSum(BinaryTreeNode<int> * root) 
{
    pair<int,int> ans = solve(root);
    return max(ans.first,ans.second);
}


// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
int main(){
    // taking input using recursion
    BinaryTreeNode<int> * root = takeInputLevelWise();
    int ans = getMaxSum(root);
    cout<<ans;
}
