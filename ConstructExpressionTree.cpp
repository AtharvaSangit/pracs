/*Assignment no = 4(Group B)
Title=Construct an expression tree from the given prefix expression eg. +--a*bc/def and traverse it using Postorder traversal (non recursive) and then delete the entire tree.*/
#include <bits/stdc++.h>
#include<stack>
using namespace std;

struct node{
    char data;
    node* left;
    node* right;
    node(char val){
        data = val;
        left = NULL; 
        right = NULL; 
    }
};

bool isOperator(char c){
    if(c=='+'|| c=='-'||c=='/'||c=='*'){
        return true;
    }
    return false;
}

node* expressionTree(string s, int n){
    stack<node*> st;
    for(int i=n-1; i>=0; i--){
        if(!isOperator(s[i])){
            node* t = new node(s[i]);
            st.push(t);
        }
        else{
            node * t = new node(s[i]);
            node* t1 = st.top();
            st.pop();
            t->right = t1;
            node* t2 = st.top();
            st.pop();
            t->left = t2;
            
            st.push(t);
        }
    }
    
    node* t = st.top();
    return t;
}

void Inorder(node* root){
    if(root == NULL){
       return;
    }
        Inorder(root->left);
        cout<<root->data;
        Inorder(root->right);
    
}

int main() {
    string s;
    cin>>s;
    node* root = expressionTree(s, s.length());
    Inorder(root);
    return 0;
}
