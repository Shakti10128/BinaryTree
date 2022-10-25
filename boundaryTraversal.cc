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


/*----------------------------Boundary Traversal------------------------------*/

void traverseLeft(BinaryTreeNode<int> * root,vector<int> & temp){
    // base case
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }
    temp.push_back(root->data);
    if(root->left){
        traverseLeft(root->left,temp);
    }
    else{
        traverseLeft(root->right,temp);
    }
}

void traverseLeafNode(BinaryTreeNode<int> * root, vector<int> & temp){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        temp.push_back(root->data);
        return;
    }

    traverseLeafNode(root->left,temp);
    traverseLeafNode(root->right,temp);
}



void traverseRight(BinaryTreeNode<int> * root,vector<int> & temp){
    // base case
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }
    if(root->right){
        traverseRight(root->right,temp);
    }
    else{
        traverseRight(root->left,temp);
    }
    temp.push_back(root->data);
}

vector<int> boundaryTraversal(BinaryTreeNode<int> * root){
    vector<int> temp;
    if(root == NULL){
        return temp;
    }
    temp.push_back(root->data);

    // function calling for left childs
    traverseLeft(root->left,temp);

    // function calling for left part of leaf node
    traverseLeafNode(root->left,temp);

    // function calling for right part of leaf node
    traverseLeafNode(root->right,temp);

    // function calling for right childs
    traverseRight(root->right,temp);

    return temp;

}




// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
// 2 5 3 4 6 7 -1 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> * root = takeInputLevelWise();
    printLevelWise(root);
    vector<int> ans = boundaryTraversal(root);
    cout<<endl;
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
