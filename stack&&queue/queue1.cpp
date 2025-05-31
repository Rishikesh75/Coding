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
    struct node*temp = new node();
    temp->value = value;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}
pair<struct node*,struct node*> create_dq()
{
    struct node *head = nullptr;
    struct node *tail = nullptr;
    return  make_pair(head,tail);
}
pair<struct node *,struct node *>insert_dequeue(pair<struct node *,struct node*>queue,int value)
{
    struct node *new_node = create_node(value);
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
pair<struct node *,struct node*>delete_queue(pair<struct node *,struct node *>queue)
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
    return queue;
}
void display_queue(pair<struct node *,struct node *>queue)
{
    if(queue.first == nullptr)
    {
        cout<<"Queue is empty\n";
        return;
    }
    while(queue.first!=nullptr)
    {
        cout<<queue.first->value<<"\t";
        queue.first = queue.first->right;
    }
    cout<<"\n";
}
int main()
{
    pair<struct node*,struct node*>queue = create_dq();
    int temp;
    cout<<"Enter the Value"<<endl;
    cin>>temp;
    queue = insert_dequeue(queue,temp);
    display_queue(queue);
    display_queue(queue);
    queue = delete_queue(queue);
    display_queue(queue);
    return(0);
}