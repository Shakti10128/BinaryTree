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


/*------------------------------buildTree---------------------------------*/

void mapping(map<int,int> &nodeToIndex,int *in,int n){
    for(int i = 0; i<n; i++){
        nodeToIndex[in[i]] = i;
    }
}
    
BinaryTreeNode<int>* solve(int *in,int * pos,int &index,int inStart,int inEnd,int n,map<int,int> &nodeToIndex){
    if(index <0 || inStart>inEnd){
        return NULL;
    }
    int element = pos[index--];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(element);
    int indexPosition = nodeToIndex[element];
    
    root->right = solve(in,pos,index,indexPosition+1,inEnd,n,nodeToIndex);
    root->left = solve(in,pos,index,inStart,indexPosition-1,n,nodeToIndex);
    return root;
}

BinaryTreeNode<int>* buildTree1(int in[],int pos[], int n)
{
    // Code here
    int index = n-1;
    map<int,int> nodeToIndex;
    mapping(nodeToIndex,in,n);
    BinaryTreeNode<int>* ans = solve(in,pos,index,0,n-1,n,nodeToIndex);
    return ans;
}


// in 4 8 2 5 1 6 3 7
// pos 8 4 5 2 6 7 3 1
int main(){
    cout<<"Enter the size of array"<<endl;
    int size;
    cin>>size;
    cout<<"Enter the element of inOrder array"<<endl;
    int in[size];
    for(int i = 0;i<size;i++){
        cin>>in[i];
    }
    cout<<endl<<"Enter the element of postOrder array"<<endl;
    int pos[size];
    for(int i = 0;i<size;i++){
        cin>>pos[i];
    }
    BinaryTreeNode<int> * ans = buildTree1(in,pos,size);
    cout<<"levelwise traversal after constructing a tree from inOrder and postOrder"<<endl;
    printLevelWise(ans);
}
