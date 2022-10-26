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

// in this approach we will solve this question without using any extra space
BinaryTreeNode<int> * solve1(BinaryTreeNode<int> *root,int &k,int node){
    if(root == NULL){
        return 0;
    }
    if(root->data == node){
        return root;
    }

    BinaryTreeNode<int> * left = solve1(root->left,k,node);
    BinaryTreeNode<int> * right = solve1(root->right,k,node);

    if(left!=NULL && right == NULL){
        k--;
        if(k<=0){
            // lock this node as final answer
            k = INT_MAX;
            return root;
        }
        return left;
    }
    if(left==NULL && right != NULL){
        k--;
        if(k<=0){
            // lock this node as final answer
            k = INT_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}

// in this approach we are using an extra space by vector<int>
void solve(BinaryTreeNode<int> * root, int k,int node,vector<int> ans,int &res){
    if(root == NULL){
        return;
    }
    if(root->data == node){
        int size = ans.size();
        for(int i = size-1;i>=0;i--){
            if(i == size-k){
                res = ans[i];
                break;
            }
        }
    }
    ans.push_back(root->data);
    solve(root->left,k,node,ans,res);
    solve(root->right,k,node,ans,res);
    ans.pop_back();
}

int kthAncestor(BinaryTreeNode<int> * root, int k, int node)
{
    // vector<int> ans;
    // int res = -1;
    // solve(root,k,node,ans,res);
    BinaryTreeNode<int> * ans = solve1(root,k,node);
    if(ans == NULL)
        return -1;
    else
        return ans->data;
}


// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> * root = takeInputLevelWise();
    int ans = kthAncestor(root,2,8);
    cout<<ans;
}
