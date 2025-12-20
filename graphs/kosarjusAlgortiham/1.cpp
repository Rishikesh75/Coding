#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<algorithm>
using namespace std;
vector<list<int>> CreateGraph(int n)
{
    vector<list<int>>graph(n);
    int v =0;
    int temp;
    for(auto it = graph.begin();it!=graph.end();it++)
    {
        while(1)
        {
            cout<<"Enter the Neighbours of"<<v;
            cin>>temp;
            if(temp == -1)
            {
                break;
            }
            (*it).push_back(temp);
        }   
        v++;
    }
    return graph;
}
void Display(vector<list<int>>&graph)
{   
    for(auto it=graph.begin();it!=graph.end();it++)
    {
        for(auto j = (*it).begin();j!=(*it).end();j++)
        {
            cout<<(*j)<<"\t";
        }
        cout<<"\n";
    }
}
void DFS(int u,vector<bool>&visitedarr,stack<int>&s,vector<list<int>>graph)
{
    visitedarr[u]  = true;
    for(auto v : graph[u])
    {
        if(!visitedarr[v])
        {
            DFS(v,visitedarr,s,graph);
        }
    }
    s.push(u);
}
vector<list<int>> ReversedGraph(vector<list<int>>Graph)
{
    vector<list<int>>reversedgraph(Graph.size());
    for(int i=0;i<Graph.size();i++)
    {
        for(int v : Graph[i])
        {
            reversedgraph[v].push_back(i);
        }
    }
    return reversedgraph;
}
vector<int>scc;
void Dfs(int u,vector<list<int>>&reversedgraph,vector<bool>&visitedarr)
{
    // cout<<"hi"<<endl;
    visitedarr[u] = true;
    scc.push_back(u);
    for(auto v : reversedgraph[u])
    {
        if(!visitedarr[v])
        {
            Dfs(v,reversedgraph,visitedarr);
        }
    }
}
void Kosarajus(vector<list<int>>&graph)
{
    int n = graph.size();
    vector<vector<int>>ans;
    vector<bool>visitedarr(n,false);
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        if(!visitedarr[i])
        {
            DFS(i,visitedarr,s,graph);
        }
    }
    fill(visitedarr.begin(), visitedarr.end(), false);
    vector<list<int>>reversedgraph = ReversedGraph(graph);
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        if(!visitedarr[node])
        {
            Dfs(node,reversedgraph,visitedarr);
            ans.push_back(scc);
            scc.clear();
        }
    }

    for(int i=0;i<ans.size();i++)
    {
        cout<<"Scc:";
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
int main()
{
    int n;
    cin>>n;
    vector<list<int>>graph(n);
    graph = CreateGraph(n);
    Kosarajus(graph);
    Display(graph);
    return 0;
}