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


vector <int> bottomView(BinaryTreeNode<int> * root) {
                vector<int> ans;
        if(root == NULL){
            return ans;
        }
        map<int,int> topNode;
        queue<pair<BinaryTreeNode<int> *,int> > q;
        q.push(make_pair(root,0));
        while(q.size()!=0){
            pair<BinaryTreeNode<int> *,int> temp = q.front();
            q.pop();
            BinaryTreeNode<int> * front = temp.first;
            int hd = temp.second;
            
                topNode[hd] = front->data;
            if(front->left){
                q.push(make_pair(front->left,hd-1));
            }
            if(front->right){
                q.push(make_pair(front->right,hd+1));
            }
        }
        
        for(auto i:topNode){
            ans.push_back(i.second);
        }
        return ans;
}


// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> * root = takeInputLevelWise();
    vector<int> ans = bottomView(root);

    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
