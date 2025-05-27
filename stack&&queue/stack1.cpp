#include<iostream>
#include<climits>
using namespace std;
struct node 
{
    int value;
    struct node * next;
};
struct node *create_stack()
{
    struct node *head = nullptr;
    return head;
}
struct node * create_node(int value)
{
    struct node *head = new node();
    head->value = value;
    head->next = nullptr;
    return head;
}
struct node * insert_stack(struct node *head,int value)
{
    struct node *temp = create_node(value);
    if(head == nullptr)
    {
        head = temp;
    }
    else if(head!=nullptr)
    {
        struct node *prev = head;
        temp->next = prev;
        head = temp;
    }
     return head;
}
void display(struct node *head)
{
    while(head!=nullptr)
    {
        cout<<head->value<<"\t";
        head = head->next;
    }
    cout<<"\n";
}
struct node* pop(struct node *head)
{
    if(head == nullptr)
    {
        cout<<"Enter the stack is empty"<<endl;
    }
    else
    {
        struct node *prev = head;
        int value = prev->value;
        head = head->next;
    }
    return head;
}
bool isEmpty(struct node *head)
{
    if(head == nullptr)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
int top(struct node *head)
{
    if(head == nullptr)
    {
        return INT_MIN;
    }
    else
    {
        return head->value;
    }
}
int main()
{

    struct node *head = create_stack();
    head = insert_stack(head,1);
    head = insert_stack(head,2);
    display(head);
    head = pop(head);
    display(head);
    cout<<top(head)<<endl;
    return(0);
}