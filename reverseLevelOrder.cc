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


/*------------------------------------reverseLevelOrder------------------------------------*/

vector<int> reverseLevelOrder(BinaryTreeNode<int>*root)
{
    stack<BinaryTreeNode<int>*> st;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    vector<int> temp;
    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        st.push(front);
        q.pop();
        if(front->right){
            q.push(front->right);
        }
        if(front->left){
            q.push(front->left);
        }
    }
    
    while(!st.empty()){
        temp.push_back(st.top()->data);
        st.pop();
    }
    return temp;
}


// 10 20 30 40 50 -1 60 70 -1 80 -1 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();

    vector<int> ans = reverseLevelOrder(root);
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
