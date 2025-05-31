#include<iostream>
using namespace std;
struct node 
{
    int value;
    struct node *left;
    struct node *Right;
};
struct node* create_tree_root()
{
    struct node *root = nullptr;
    return root;
}
struct node *create_node(int value)
{
    struct node *root = new node();
    root->left = nullptr;
    root->Right = nullptr;
    root->value = value;
    return root;
}
struct node* create_tree(struct node*root,struct node *temp)
{
char c;
if(root == nullptr)
{
    root = temp;
}
else
{
    cout<<"Enter L to insert the Left of node or R to insert Right of the node";
    cin>>c;
    if(c == 'L')
    {
        root->left = create_tree(root->left,temp);
    }
    else
    {
        root->Right = create_tree(root->Right,temp);
    }
}
return root;
}
void inorder_traversal(struct node *root)
{
    if(root == nullptr)
    {
        return;
    }
    inorder_traversal(root->left);
    cout<<root->value<<"\t";
    inorder_traversal(root->Right);
}
void preorderTraversal(struct node *root)
{
    if(root == nullptr)
    {
        return;
    }
    else 
    {
        cout<<root->value<<"\t";
        preorderTraversal(root->left);
        preorderTraversal(root->Right);
    }
}

int main()
{
    struct node *root = create_tree_root();
    int temp;
    cin>>temp;
    struct node* new_node =create_node(temp);
    root = create_tree(root,new_node);
    inorder_traversal(root);
    return(0);
}