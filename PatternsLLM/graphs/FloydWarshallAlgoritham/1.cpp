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
void intialize_arr(vector<vector<int>>&Distance,vector<list<pair<int,int>>>Graph)
{
    for(int i=0;i<Graph.size();i++)
    {
        for(auto it = Graph[i].begin();it!=Graph[i].end();it++)
        {
            if(Distance[i][it->first]>it->second)
            {
                Distance[i][it->first] = it->second;
            }
        }
    }
}
void DisplayDistancearr(vector<vector<int>>Distance)  
{
    for(auto arr : Distance)
    {
        for(auto dis : arr)
        {
            cout<<dis<<"\t";
        }
        cout<<"\n";
    }
}
void FloydWarshallAlgoritham(int n,vector<list<pair<int,int>>>Graph)
{
    //Initialize the Distacne Array
    vector<vector<int>>Distance(n,vector<int>(n,INT_MAX));
    intialize_arr(Distance,Graph);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(Distance[j][i]!=INT_MAX && Distance[i][k]!=INT_MAX)
                {
                    if(Distance[j][k]>Distance[j][i]+Distance[i][k])
                    {
                        Distance[j][k]=Distance[j][i]+Distance[i][k];
                    }
                }
            }
        }
    }
    DisplayDistancearr(Distance);
}
int main()
{
    int n;
    cin>>n;
    vector<list<pair<int,int>>>Graph(n);
    CreateGraph(Graph,n);
    display(Graph);
    FloydWarshallAlgoritham(n,Graph);
    return 0;
}