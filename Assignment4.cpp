/*Assignment no = 4(Group B)
Title=Construct an expression tree from the given prefix expression eg. +--a*bc/def and traverse it using Postorder traversal (non recursive) and then delete the entire tree.*/
#include <iostream>
using namespace std;
class node
{
 public:
       char data;
        node *left;
        node *right;
};
class stack 
{
        node *a[20];
        int top;
    public:
        stack()
        {
            top = -1;
        }
        void push(node *temp);
        node * pop();
        int isempty();
        int isfull();
};
void stack::push(node *temp)
{
    if(!isfull())
    {
        a[++top] = temp;
    }
    else
    {
 cout<<"\n Stack is full";
    }
}
node * stack::pop()
{
    if(!isempty())
    {
       return(a[top--]);
    }
    else
    {
        cout<<"\n Stack is empty";
        return NULL;
    }
}
int stack::isempty()
{
    if(top == -1)
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
int stack::isfull()
{
    if(top == 19)
    {
        return(1);
    }
    else
    {
        return(0);
    }
}

class Expression_Tree
{
    public:
        node *root;
        Expression_Tree()
        {
            root = NULL;
        }
        void Create_Expression_Tree();
        void infix(node *temp);
        void prefix(node *temp);
        void postfix(node *temp);
};
void Expression_Tree::Create_Expression_Tree()
{
    int i;
    char ch;
    stack s;
    node *new_node, *temp;
    char postfix_Exp[20];
    cout<<"\nEnter postfix expression : ";
    cin>>postfix_Exp;
    
    for(i = 0; postfix_Exp[i] !='\0'; i++)
    {
        ch = postfix_Exp[i];
        new_node = new node();
        new_node -> data = ch;
        new_node ->left = NULL;
        new_node ->right = NULL;
        if((ch >= 'A' && ch <= 'Z' ) || (ch >= 'a' && ch <= 'z' ) )
        {
            s.push(new_node);
           
        }
        else
        {
            temp = s.pop();
            new_node->right = temp;
            temp = s.pop();
            new_node->left = temp;
            s.push(new_node);
        }
    }
    root = s.pop();
}
void Expression_Tree::infix(node * temp)
{
    if(temp != NULL)
    {
        infix(temp->left);
        cout<<" "<<temp->data;
        infix(temp->right);
    }
}
void Expression_Tree::prefix(node * temp)
{
    if(temp != NULL)
    {
        cout<<" "<<temp->data;
        prefix(temp->left);
        prefix(temp->right);
    }
}
void Expression_Tree::postfix(node * temp)
{
    if(temp != NULL)
    {
        postfix(temp->left);
        postfix(temp->right);
        cout<<" "<<temp->data;
    }
}
int main()
{
    Expression_Tree E;
    E.Create_Expression_Tree();
    cout<<"\n Infix Expression : ";
    E.infix(E.root);
    cout<<"\n prefix Expression : ";
    E.prefix(E.root);
    cout<<"\n Postfixfix Expression : ";
    E.postfix(E.root);
}
