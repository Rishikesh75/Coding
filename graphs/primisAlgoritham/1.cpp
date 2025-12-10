#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<queue>
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
void DisplayMST(vector<pair<int,pair<int,int>>>MST)
{
    cout<<"MST:";
    for(int i=0;i<MST.size();i++)
    {
        cout<<MST[i].first<<MST[i].second.first<<"("<<MST[i].second.second<<")"<<"\t";
    }
    cout<<'\n';
}
struct Comparitor
{
    bool operator()(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b)
    {
        a.second.second>b.second.second;
    }
};
void Primis(vector<list<pair<int,int>>> &Graph, int n)
{
    vector<int>visitedarr(n,0);
    vector<pair<int,pair<int,int>>> MST;

    visitedarr[0] = 1;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,Comparitor>pq;
    for(auto &edge : Graph[0])
    {
        pq.push({0,{edge.first,edge.second}});
    }

    while(!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        int u = temp.first;
        int v = temp.second.first;
        int wt = temp.second.second;

        if(visitedarr[v]) continue;
        visitedarr[v] = 1;
        MST.push_back(temp);
        for(auto& edge:Graph[v])
        {
            pq.push({v,{edge.first,edge.second}});
        }
    }

    DisplayMST(MST);
}


int main()
{
    int n;
    cin>>n;
    vector<list<pair<int,int>>>Graph(n);
    CreateGraph(Graph,n);
    display(Graph);
    Primis(Graph,n);
    return 0;
}