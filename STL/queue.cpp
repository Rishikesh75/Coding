/*
---Queue---
q.push()
q.pop()
q.front()
q.size()
q.empty()
*/
#include<iostream>
#include<queue>
using namespace std;
void Display(queue<int>queue)
{
    cout<<"Display:"<<"\t";
    while(!queue.empty())
    {
        cout<<q.front()<<"\t";
    }
    return;
}
int main()
{
    queue<int>q;
    q.push(1);
    cout<<q.front()<<endl;
    q.pop();
    if(q.empty())
    {
        cout<<"Return queue is empty.."<<endl;
    }
    return 0;
}