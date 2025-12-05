#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
void Creategraph(vector<list<int>>&Graph,int n)
{
    int num;
    for(int i=0;i<n;i++)
    {
        while(1)
        {
            cout<<"Enter the Edges to"<<i<<":";
            cin>>num;
            if(num == -1)
            {
                break;
            }
            Graph[i].push_back(num);
        }
    }
}
void Dfs(vector<list<int>>&Graphs,int n)
{
    cout<<"dfs:";
    stack<int>s;
    vector<int>visitedarr(n,0);
    s.push(0);
    visitedarr[0] = 1;
    while(!s.empty())
    {
        int value = s.top();
        cout<<value<<"\t";
        s.pop();
        for(auto it = Graphs[value].begin();it!=Graphs[value].end();it++)
        {
            if(visitedarr[*it]==0)
            {
                s.push(*it);
                visitedarr[*it] = 1;
            }   
        }
    }
    return;
}
void Display(vector<list<int>>&Graph,int n)
{
    for(auto it = Graph.begin();it!=Graph.end();it++)
    {
        for(auto it_1 = (*it).begin();it_1!=(*it).end();it_1++)
        {
            cout<<*it_1<<"\t";
        }
        cout<<"\n";
    }
}
int main()
{
    int n;
    cin>>n;
    vector<list<int>>Graph(n);
    Creategraph(Graph,n);
    Display(Graph,n);
    Dfs(Graph,n);
    return 0;
}