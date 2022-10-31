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


/*-------------------------------leaf at same level------------------------------------*/

void solve(BinaryTreeNode<int>* root,int lvl,vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right ==NULL){
        ans.push_back(lvl);
    }
    solve(root->left,lvl+1,ans);
    solve(root->right,lvl+1,ans);
    
}

bool check(BinaryTreeNode<int>*root)
{
    if(root == NULL)
    return false;
    vector<int> ans;
    solve(root,0,ans);
    
    int val = ans[0];
    for(int i =  0;i<ans.size();i++){
        if(ans[i]!=val)
           return false;
    }
    return true;
}



// 1 2 3 4 5 -1 9 6 -1 -1 7 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    bool ans = check(root);
    if(ans)
       cout<<"Leaf are on same level"<<endl;
    else
       cout<<"Leaf aren't on same level"<<endl;
}
