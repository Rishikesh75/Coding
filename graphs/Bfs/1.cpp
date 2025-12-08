#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
void CreateGraph(vector<list<int>> &Graph,int n)
{
    Graph.resize(n);
    int num;
    for(int i=0;i<n;i++)
    {
        while(1)
        {
            cout<<"Enter the Neighbours of"<<i<<":";
            cin>>num;
            if(num == -1)
            {
                break;
            }
            Graph[i].push_back(num);
        }
    }
}
void display(vector<list<int>> &Graph,int n)
{
    for(int i=0;i<Graph.size();i++)
    {
        cout<<i<<":";
        for(auto it = Graph[i].begin();it!=Graph[i].end();it++)
        {
            cout<<*it<<"\t";
        }
        cout<<"\n";
    }
}
void bfs(vector<list<int>> &Graph,int n)
{
    vector<int>visitedarr(n,0);
    queue<int>q;
    q.push(0);
    visitedarr[0] = 1;
    while(!q.empty())
    {
        int value = q.front();
        q.pop();
        cout<<value<<"\t";
        for(auto it = Graph[value].begin();it!=Graph[value].end();it++)
        {
             if(visitedarr[*it] == 0)
             {
                q.push(*it);
                visitedarr[*it]=1;
             }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<list<int>>Graph;
    CreateGraph(Graph,n);
    display(Graph,n);
    bfs(Graph,n);
    return 0;
}