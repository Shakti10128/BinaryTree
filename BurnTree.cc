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


/*------------------------------BurnTree---------------------------------*/


BinaryTreeNode<int> * createMapping(BinaryTreeNode<int> * root,int target,map<BinaryTreeNode<int> *,BinaryTreeNode<int> *> & findParent){
    BinaryTreeNode<int> * TargetNode = NULL;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    findParent[root] = NULL;
    while(!q.empty()){
        BinaryTreeNode<int> * front = q.front();
        q.pop();
        if(front->data == target){
            TargetNode = front;
        }
        if(front->left){
            findParent[front->left] = front;
            q.push(front->left);
        }
        if(front->right){
            findParent[front->right] = front;
            q.push(front->right);
        }
    }
    return TargetNode;
}


int burnTree(BinaryTreeNode<int> * root,map<BinaryTreeNode<int> *,BinaryTreeNode<int> *> & findParent){
    int ans = 0;
    map<BinaryTreeNode<int> *,bool> vis;
    vis[root] = true;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        bool flag = false;
        for(int i = 0;i<size;i++){
            BinaryTreeNode<int> * front = q.front();
            q.pop();
            if(front->left && !vis[front->left]){
                vis[front->left] = true;
                q.push(front->left);
                flag = true;
            }
            if(front->right && !vis[front->right]){
                vis[front->right] = true;
                q.push(front->right);
                flag = true;
            }
            if(findParent[front] && !vis[findParent[front]]){
                vis[findParent[front]] = true;
                q.push(findParent[front]);
                flag = true;
            }
        }
        if(flag == true){
            ans++;
        }
    }
    return ans;
}


int minTime(BinaryTreeNode<int> * root, int target) {
    // Your code goes here
    map<BinaryTreeNode<int> *,BinaryTreeNode<int> *> findParent;
    BinaryTreeNode<int> * targetNode = createMapping(root,target,findParent);
    int ans = burnTree(targetNode,findParent);
    return ans;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> * root = takeInputLevelWise();
    int ans = minTime(root,8);
    cout<<ans<<endl;
}
