/*Dobule ended Queue */
#include<iostream>
using namespace std;
struct node 
{
    int value;
    struct node *left;
    struct node *right;
};
struct node *create_node(int value)
{
    struct node = new node();
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
pair<struct node*,struct node*> create_dq()
{
    struct node *head = nullptr;
    struct node *tail = nullptr;
    return  make_pair(head,tail);
}
pair<struct node *,struct node *>insert_dequeue(pair<struct node *,struct node*>queue,int value)
{
    struct node *new_node = new node();
    if(queue.first == nullptr && queue.second == nullptr)
    {   
        queue.first  = new_node;
        queue.second = new_node;
    }
    else 
    {
        queue.second->right = new_node;
        new_node->left = queue.second;
        queue.second = new_node;
    }
    return make_pair(queue.first,queue.second);
}
pair<struct node *,struct node*>deletequeue(<struct node *,struct node *>queue)
{
    if(queue.first == nullptr && queue.second == nullptr)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else if(queue.first == queue.second)
    {
        struct node *temp = queue.first;
        queue.first = nullptr;
        queue.second = nullptr;
        free(temp);
    }
    else
    {
        struct node *temp = queue.first;
        queue.first = queue.first->right;
        free(temp);
    }
    return queue
}
void display_queue(pair<struct node *,struct node *>queue)
{
    while(queue.first!=nullptr)
    {
        cout<<queue.first->value<<"\t";
    }
    cout<<"\n";
}
int main()
{


    return(0);
}