#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
vector<list<int>> CreateGraph(int n)
{
    int temp;
    vector<list<int>>graph(n);
    for(int i=0;i<n;i++)
    {
        while(1)
        {
            cout<<"Enter the Neighbour of"<<i;
            cin>>temp;
            if(temp == -1)
            {
                break;
            }
            graph[i].push_back(temp);
        }
    }
    return graph;
}
void Display(vector<list<int>>graph)
{
    cout<<"Graph:"<<"\n";
    for(auto it = graph.begin();it!=graph.end();it++)
    {
        for(auto j = (*it).begin();j!=(*it).end();j++)
        {
            cout<<(*j)<<"\t";
        }
        cout<<"\n";
    }
}
void DFS(int u,vector<int>&disc,vector<int>&low,vector<bool>&Instack,stack<int>&mystack,vector<list<int>>&Graph)
{
    static int time = 0;
    disc[u] = low[u] = time;
    mystack.push(u);
    Instack[u] = 1;
    for(auto v : Graph[u])
    {
        if(disc[v] == -1)
        {
            DFS(v,disc,low,Instack,mystack,Graph);
            low[u] = min(low[u],low[v]);
        }
        else if(Instack[v])
        {
            low[u] = min(low[u],disc[v]);
        }
    }
    if(low[u] == disc[u])
    {
        cout<<"SCC is :";
        while(mystack.top()!=u)
        {
            cout<<mystack.top()<<"\t";
            Instack[mystack.top()] = false;
            mystack.pop();
        }
        cout<<mystack.top()<<"\n";
        Instack[mystack.top()]=false;
        mystack.pop();
    }
}
void FindTarjanAlgorithm(int n,vector<list<int>>graph)
{
    vector<int>disc(n,-1),low(n,-1);
    vector<bool>Instack(n,false);
    stack<int>mystack;
    for(int i=0;i<n;i++)
    {
        if(disc[i] == -1)
        {
            DFS(i,disc,low,Instack,mystack,graph);
        }
    }

}
int main()
{
    int n;
    cin>>n;
    vector<list<int>>graph = CreateGraph(n);
    Display(graph);
    FindTarjanAlgorithm(n,graph);
    return 0;
}