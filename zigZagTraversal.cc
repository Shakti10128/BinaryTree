#include<bits/stdc++.h>
#include"BinaryTreeClass.cc"
using namespace std;
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

/*----------------------------ZigZag Traversal------------------------------*/

vector <int> zigZagTraversal(BinaryTreeNode<int>* root){
    	  vector<int> v;
        if(root==NULL)
            return v;
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        bool d=true;
        int k=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                BinaryTreeNode<int> *curr=q.front();
                q.pop();
                if(d==true){
                    v.push_back(curr->data);
                }
                if(d==false){
                    v.insert(v.begin()+k,curr->data);
                }
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            d=!d;
            k=v.size();
        }
        return v;
}

// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
// 2 5 3 4 6 7 -1 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> * root = takeInputLevelWise();
    printLevelWise(root);
    vector<int> ans = zigZagTraversal(root);
    cout<<endl;
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
