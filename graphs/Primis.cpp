#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
vector<list<pair<int,int>>> CreateArray(int n)
{
    int temp;
    vector<list<pair<int,int>>>arr(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"Enter the Edge Weight b/w:"<<i<<j<<endl;
            cin>>temp;
            if(temp != 0)
            {
                arr[i].push_back(make_pair(temp,j));
            }
        }
    }
    return arr;
}
void display(vector<list<pair<int,int>>>arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(auto it = arr[i].begin();it!=arr[i].end();it++)
        {
            cout<<"("<<it->first<<","<<it->second<<")"<<"\t";
        }
        cout<<"\n";
    }
}
struct comparor
{
    bool operator()(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b)
    {
        return a.first>b.first;// a is the existing element and b is the new element
    }
};
//(wt,CurrentNode,ParentValue);
//(wt,nextnode);
pair<int,pair<int,int>> group(int a,int b,int c)
{
    return make_pair(a,make_pair(b,c));
}

void PrimsAlgorithams(vector<list<pair<int,int>>>arr,int n)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,comparor>pq;
    vector<int>Visitedarr(n,0);
    pq.push(group(-1,0,-1));
    while(!pq.empty())
    {
        pair<int,pair<int,int>>value = pq.top();
        pq.pop();
        if( Visitedarr[value.second.first] == 0)
        {
           if(value.first != -1)
           {
            cout<<value.second.first<<value.second.second<<"\t";
           }
            Visitedarr[value.second.first] = 1;
            for(auto it = arr[value.second.first].begin();it!= arr[value.second.first].end();it++)
            {
                if(Visitedarr[it->second] == 0)
                {
                    pq.push(group(it->first,it->second,value.second.first));
                }
            }
        }
    }
}
int main()
{

    int n;
    cin>>n;
    vector<list<pair<int,int>>> arr = CreateArray(n);
    display(arr,n);
    PrimsAlgorithams(arr,n);

    return 0;
}