#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;
vector<list<int>>CreateGraph(int vertices)
{
    vector<list<int>> Graph(vertices, list<int>(0));
    int temp;
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            cout<<"Enter 1 if there is edge from"<<i<<j<<":";
            cin>>temp;
            if(temp == 1)
            {
                Graph[i].push_back(j);
            }
        }
    }
    return Graph;
}
void DisplayGraph(vector<list<int>>Graph)
{
    for(int i=0;i<Graph.size();i++)
    {
        cout<<i<<":";
        for(auto start = Graph[i].begin();start!=Graph[i].end();start++)
        {
            cout<<*start<<"\t";
        }
        cout<<"\n";
    }
}
void bfs(vector<list<int>>Graph)
{   
    int startnode =0;
    queue<int>q;
    vector<int>Visistedarr(Graph.size(),0);
    q.push(startnode);
    Visistedarr[startnode] = 1;
    while(!q.empty())
    {
        int vertex = q.front();
        q.pop();
        cout<<vertex<<"\t";
        for(auto start = Graph[vertex].begin();start!=Graph[vertex].end();start++)
        {
            if(Visistedarr[*start] == 0)
            {
                q.push(*start);
                Visistedarr[*start] = 1;
            }
        }
    }
    cout<<"\n";
}
void dfs(vector<list<int>>Graph)
{   
    int startnode =0;
    stack<int>q;
    vector<int>Visistedarr(Graph.size(),0);
    q.push(startnode);
    Visistedarr[startnode] = 1;
    while(!q.empty())
    {
        int vertex = q.top();
        q.pop();
        cout<<vertex<<"\t";
        for(auto start = Graph[vertex].begin();start!=Graph[vertex].end();start++)
        {
            if(Visistedarr[*start] == 0)
            {
                q.push(*start);
                Visistedarr[*start] = 1;
            }
        }
    }
    cout<<"\n";
}
int main()
{
    int vertices;
    cin>>vertices;
    vector<list<int>>Graph = CreateGraph(vertices);
    DisplayGraph(Graph);
    bfs(Graph);
    dfs(Graph);
    return(0);
}