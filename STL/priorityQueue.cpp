#include<iostream>
#include<queue>
using namespace std;
struct comparitor
{
    bool operator()(int a, int b) const
    {
        return a > b;  // makes it a min-heap
    }
};
int main()
{
    priority_queue<int,vector<int>,comparitor>pq;
    pq.push(5);
    pq.push(1);
    pq.push(3);

    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}