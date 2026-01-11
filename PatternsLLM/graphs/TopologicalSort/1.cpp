//Kahns Algoritham
#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
void CreateGraph(int n,vector<list<int>>&Graph)
{
    int num;
    for(int i=0;i<n;i++)
    {
        while(1)
        {
            cout<<"Enter the Neightbours of"<<i<<":";
            cin>>num;
            if(num == -1)
            {
                break;
            }
            Graph[i].push_back(num);
        }
    }
}
void Display(vector<list<int>>Graph)
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
void KansAlgoritham(int n,vector<list<int>>Graph)
{
    vector<int>indegree(Graph.size(),0);
    for(int i=0;i<Graph.size();i++)
    {
        for(auto it = Graph[i].begin();it!=Graph[i].end();it++)
        {
            indegree[*it] = indegree[*it] + 1;
        }
    }

    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
            break;
        }
    }
    vector<int>TopologicalOrder;
    while(!q.empty())
    {
        int temp = q.front();
        TopologicalOrder.push_back(temp);
        q.pop();

        for(auto &edge : Graph[temp])
        {
            indegree[edge] = indegree[edge] - 1;
            if(indegree[edge] == 0)
            {
                q.push(edge);
            }
        }
    }
    cout<<"Order"<<":";
    for(int i=0;i<TopologicalOrder.size();i++)
    {
        cout<<TopologicalOrder[i]<<"\t";
    }

}
int main()
{
    int n;
    cin>>n;
    vector<list<int>>Graph(n);
    CreateGraph(n,Graph);
    Display(Graph);
    KansAlgoritham(n,Graph);
    return 0;
}