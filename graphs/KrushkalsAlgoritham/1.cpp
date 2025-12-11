#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
class DSU
{
    vector<int>parent;
    vector<int>rank;
    
    public :

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int Find(int X)
    {
        if(parent[X]!=X)
        {
            parent[X] = Find(parent[X]);
        }
        return parent[X];
    }
    void Union(int x,int y)
    {
        int rootX = Find(x);
        int rootY = Find(y);
        if(rootX == rootY)
        {
            return;
        }
        if(rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else if(rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX] = rank[rootX] + 1;
        }
    }
};
void CreateGraph(vector<list<pair<int,int>>>&Graph)
{
    int num;
    int wt;
    for(int i=0;i<Graph.size();i++)
    {
        while(1)
        {
            cout<<"Enter the Neighbour of"<<i<<":";
            cin>>num;
            if(num == -1)
            {
                break;
            }
            cout<<"Enter the wt"<<i<<num<<":";
            cin>>wt;
            Graph[i].push_back({num,wt});
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
            cout<<"("<<it->first<<it->second<<")\t";
        }
        cout<<"\n";
    }
}
struct Comparitor
{
    bool operator()(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b)
    {
        a.second.second > b.second.second;
    }
};
void KrushkalsAlgorithm(vector<list<pair<int,int>>>Graph,int n)
{
    vector<pair<int,pair<int,int>>>Edges;
    auto dsu = DSU(n);
    for(int i=0;i<n;i++)
    {
        for(auto it = Graph[i].begin();it!=Graph[i].end();it++)
        {
            Edges.push_back({i,{it->first,it->second}}); //(src,(final,distane))
        }
    }

    sort(Edges.begin(),Edges.end(),Comparitor());
    vector<pair<int,pair<int,int>>>MST;
    for(auto &edge : Edges)
    {
        int u = edge.first;
        int v = edge.second.first;
        int wt = edge.second.second;

        if(dsu.Find(u)!=dsu.Find(v))
        {
            dsu.Union(u,v);
            MST.push_back(edge);
        }
    }
    
    for(auto it = MST.begin();it!=MST.end();it++)
    {
        cout<<it->first<<it->second.first<<"("<<it->second.second<<")"<<"\n";
    }
}
int main()
{
    int n;
    cin>>n;
    vector<list<pair<int,int>>>Graph(n);
    CreateGraph(Graph);
    display(Graph);
    KrushkalsAlgorithm(Graph,n);
    return 0;
}