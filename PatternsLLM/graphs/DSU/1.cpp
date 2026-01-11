#include<iostream>
#include<vector>
#include<list>
using namespace std;
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
            cout<<"Enter the Weight b/w "<<i<<num<<":";
            cin>>wt;
            Graph[i].push_back({num,wt});
        }
    }
}
void DisplayGraph(vector<list<pair<int,int>>>Graph)
{
    for(int i=0;i<Graph.size();i++)
    {
        cout<<i<<":";
        for(auto it = Graph[i].begin();it!=Graph[i].end();it++)
        {
            cout<<"("<<it->first<<it->second<<")";
        }
        cout<<"\n";
    }
}
void IntializepParentArr(int n,vector<int>&parent)
{
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
    }
}
int Find(int x,vector<int>&parent)
{
    if(parent[x]!=x)
    {
        parent[x] = Find(parent[x],parent);
    }
    return parent[x];
}
void FindUnion(int x,int y,vector<int>&parent,vector<int>&rank)
{
    int rootX = Find(x,parent);
    int rootY = Find(y,parent);
    if(rootX == rootY)
    {
        return;
    }
    if(rank[rootX]< rank[rootY])
    {
        parent[rootX] = rootY;
    }
    else if(rank[rootX]> rank[rootY])
    {
        parent[rootY] = rootX;
    }
    else 
    {
        parent[rootY] = rootX;
        rank[rootX] = rank[rootX] + 1;
    }
}
void DSU(vector<list<pair<int,int>>>Graph,int n)
{
    vector<int>parent(n,0);
    vector<int>rank(n,0);
    IntializepParentArr(n,parent);
    for(int i=0;i<Graph.size();i++)
    {
        for(auto it=Graph[i].begin();it!=Graph[i].end();it++)
        {
            FindUnion(i,it->first,parent,rank);
        }
    }
    for(int i=0;i<parent.size();i++)
    {
        cout<<parent[i]<<"\t";
    }
    cout<<"\n";
    for(int i=0;i<rank.size();i++)
    {
        cout<<rank[i]<<"\t";
    }
    cout<<"\n";

}

int main()
{
    int n;
    cin>>n;
    vector<list<pair<int,int>>>Graph(n);
    CreateGraph(Graph);
    DisplayGraph(Graph);
    DSU(Graph,n);
    return 0;
}