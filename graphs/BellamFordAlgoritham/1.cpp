#include<iostream>
#include<vector>
#include<list>
#include<climits>
using namespace std;
void CreateGraph(vector<list<pair<int,int>>>&Graph,int n)
{
    int num;
    int weight;
    for(int i=0;i<n;i++)
    {
        while(1)
        {
            cout<<"Enter the neighbours of"<<i<<":";
            cin>>num;
            if(num==-1)
            {
                break;
            }
            cout<<"Enter the Weight of the Edge:";
            cin>>weight;
            Graph[i].push_back(make_pair(num,weight));
        }
    }
}
void display(vector<list<pair<int,int>>>&Graph)
{
    for(int i=0;i<Graph.size();i++)
    {
        cout<<i<<":";
        for(auto it=Graph[i].begin();it!=Graph[i].end();it++)
        {
            cout<<"("<<it->first<<it->second<<")"<<"\t";
        }
        cout<<"\n";
    }
}
void DisplayDistanceArr(vector<int>arr)
{
    cout<<"Distances:"<<"\t";
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";

}
void BellamanFoldAlgoritham(vector<list<pair<int,int>>>&Graph,int n,int startnode)
{
    vector<int>Distance(n,INT_MAX);
    Distance[startnode] = 0;
    
    for(int i=0;i<Graph.size();i++)
    {
        for(int j=0;j<Graph.size();j++)
        {
            for(auto it = Graph[j].begin();it!=Graph[j].end();it++)
            {
                if(Distance[j]!=INT_MAX && Distance[j]+it->second<Distance[it->first])
                {
                    Distance[it->first] = Distance[j]+it->second;
                }
            }
        }
    }

    for(int j=0;j<Graph.size();j++)
    {
        for(auto it = Graph[j].begin();it!=Graph[j].end();it++)
        {
            if(Distance[j]!=INT_MAX && Distance[j]+it->second<Distance[it->first])
            {
                cout<<"Negative weight cycle detected"<<endl;
                return;
            }
        }
    }
    DisplayDistanceArr(Distance);
    return;

}
int main()
{
    int n;
    cin>>n;
    vector<list<pair<int,int>>>Graph(n);
    CreateGraph(Graph,n);
    display(Graph);
    BellamanFoldAlgoritham(Graph,n,0);
    return 0;
}