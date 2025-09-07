#include<iostream>
#include<queue>
using namespace std;
struct  Compare
{
    bool operator()(int a,int b)
    {
        return a>b;
    }
};
int main()
{
    priority_queue<int,vector<int>,Compare>pq;
    pq.push(1);
    pq.push(2);
    while(!pq.empty())
    {
        cout<<pq.top()<<"\t";
        pq.pop();
    }
    return(0);
}