#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
vector<list<int>>CreateGraph(int n)
{
    vector<list<int>>Graph(n);
    for(auto &neighbours : Graph)
    {
        while(1)
        {
            int temp;
            cin>>temp;
            if(temp == -1)
            {
                break;
            }
            neighbours.push_back(temp);
        }
    }
    return Graph;
}
void display(vector<list<int>>Graph)
{
    for(auto it = Graph.begin();it!=Graph.end();it++)
    {
        for(auto vertex : *it)
        {
            cout<<vertex<<"\t";
        }
        cout<<"\n";
    }
    return;
}
void dfs(vector<list<int>>Graph,int n)
{
    vector<int>Visitedarr(n,0);
    stack<int>s;
    s.push(0);
    Visitedarr[0] = 1;
    while(!s.empty())
    {
        int temp = s.top();
        cout<<temp<<"\t";
        s.pop();
        for(auto vertex : Graph[temp])
        {
            if(Visitedarr[vertex] == 0)
            {
                s.push(vertex);
                Visitedarr[vertex] = 1;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<list<int>>Graph = CreateGraph(n);
    display(Graph);
    dfs(Graph,n);
    return 0;
}