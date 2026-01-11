#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>
using namespace std;
void Createarr(vector<list<pair<int,int>>>&Graph,int n)
{
    int num;
    int dis;
    for(int i=0;i<n;i++)
    {
        while(1)
        {
            cout<<"Enter the Neighborus of"<<i<<":";
            cin>>num;
            if(num == -1)
            {
                break;
            }
            cout<<"Enter the Distance"<<i<<num<<":";
            cin>>dis;
            Graph[i].push_back(make_pair(num,dis));
        }
    }
}
void display(vector<list<pair<int,int>>>Graph)
{
    for(int i=0;i<Graph.size();i++)
    {
        cout<<i<<":";
        for(auto it = Graph[i].begin();it!=Graph[i].end();it++)
        {
            cout<<"("<<it->first<<","<<it->second<<")"<<"\t";
        }
        cout<<"\n";
    }
}
struct comparitor
{
    bool operator()(pair<int,int> a,pair<int,int>b)
    {
        return a.second>b.second;
    }   
};
void DisplayDistance(vector<int>arr)
{
    cout<<"Distance:"<<"\t";
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<"\t";
    }
}
void DisktraAlgoritham(vector<list<pair<int,int>>>Graph,int n)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,comparitor>pq;
    vector<int>Distance(n,INT_MAX);
    pq.push(make_pair(0,0));
    Distance[0] = 0;
    while(!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        for(auto neighbour:Graph[temp.first])
        {
            if(neighbour.second+temp.second<Distance[neighbour.first])
            {
                Distance[neighbour.first] = neighbour.second+temp.second;
                pq.push(make_pair(neighbour.first,neighbour.second+temp.second));
            }
        }
    }
    DisplayDistance(Distance);
}   
int main()
{
    int n;
    cin>>n;
    vector<list<pair<int,int>>>Graph(n);
    Createarr(Graph,n);
    display(Graph);
    DisktraAlgoritham(Graph,n);
    return 0;
}