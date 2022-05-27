#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


Node* insertBST(Node* root, int val){

    if(root==NULL){
        return new Node(val);
    }

    if(val<root->data){
        root->left = insertBST(root->left, val);
    }else{
        root->right=insertBST(root->right,val);
    }
    return root;
}

Node *searchInBST(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    if (key < root->data)
    {
        return searchInBST(root->left, key);
    }
    return searchInBST(root->right, key);
}

int height(Node* node){
    if(node==NULL){
        return 0;
    }
    int lht = height(node->left);
    int rht = height(node->right);
    return max(lht,rht)+1;

}

void Mirror(Node *r)
{
    Node *temp;
    if(r != NULL)
    {
        temp = r->left;
        r->left = r->right;
        r->right = temp;
        Mirror(r->left);
        Mirror(r->right);
    }
}

void smallest(Node* root)
{
    Node *temp;
    temp = root;
    while(temp ->left !=NULL)
    {
        temp = temp ->left;
    }
    cout<<"\nSmallest node in the tree is : "<<temp->data;
}
void largest(Node* root)
{
    Node *temp;
    temp = root;
    while(temp ->right !=NULL)
    {
        temp = temp ->right;
    }
    cout<<"\nSmallest node in the tree is : "<<temp->data;
}


void Inorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    Inorder(root->left);
    Inorder(root->right);

    
}


int main(){

    Node* root = NULL ;
    root = insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    Inorder(root);

    if (searchInBST(root, 15) == NULL)
    {
        cout <<"Key doesn't Exists"<<" "<<endl;
    }
    else
    {
        cout << "key exists"<<endl;
    }

    cout<<height(root)<<endl;
    
    Mirror(root);
    Inorder(root);
    smallest(root);
    largest(root);
    return 0;
}
