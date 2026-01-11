#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
vector<list<int>> CreateGraph(int n)
{
    vector<list<int>>Graph(n);
    int Nodevalue = 0;
    for(auto &node : Graph)
    {
        cout<<"Enter the Neighbours:"<<Nodevalue;
        while(1)
        {
            int temp;
            cin>>temp;
            if(temp == -1)
            {
                break;
            }
            node.push_back(temp);
        } 
        Nodevalue++;  
    }
    return Graph;
}
void display(vector<list<int>>graph)
{
    for(auto &edge : graph)
    {
        for(auto &vertex : edge)
        {
            cout<<vertex<<"\t";
        }
        cout<<"\n";
    }
}
void Dfs(vector<list<int>>graph,int n)
{
    vector<int>Visitedarr(n,0);
    queue<int>q;
    q.push(0);
    Visitedarr[0] = 1;
    while(!q.empty())
    {
        int vertex = q.front();
        cout<<vertex<<"\t";
        q.pop();
        for(auto &neighbour : graph[vertex])
        {
            if(Visitedarr[neighbour] == 0)
            {
                q.push(neighbour);
                Visitedarr[neighbour] = 1;
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
    Dfs(Graph,n);
    return 0;
}