#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
void Creatarr(vector<list<int>>&Graph,int n)
{
    for(int i=0;i<n;i++)
    {
        while(1)
        {
            int num;
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
void display(vector<list<int>>&Graph)
{
    for(int i=0;i<Graph.size();i++)
    {
        cout<<i<<":";
        for(auto it = Graph[i].begin();it!=Graph[i].end();it++)
        {
            cout<<*it<<"\t";
        }
        cout<<'\n';
    }
}
void dfs(vector<list<int>>&Graph,int n)
{
    vector<int>Visitedarr(n,0);
    Visitedarr[0]= 1;
    stack<int>s;
    s.push(0);
    while(!s.empty())
    {
        int value = s.top();
        cout<<value<<"\t";
        s.pop();
        for(auto it = Graph[value].begin();it!=Graph[value].end();it++)
        {
            if(Visitedarr[*it] == 0)
            {
                s.push(*it);
                Visitedarr[*it] = 1;
            }   
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<list<int>>Graph(n);
    Creatarr(Graph,n);
    display(Graph);
    dfs(Graph,n);
    return 0;
}