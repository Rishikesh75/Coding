#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
vector<list<int>> CreateGraph(int n)
{
    vector<list<int>> arr(n);
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp = 0;
            cout<<"Enter 1 if there is Edge B/w"<<i<<j<<endl;
            cin>>temp;
            if(temp == 1)
            {
                arr[i].push_back(j);
            }
        }
    }
    return arr;
}
void display(vector<list<int>> arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(auto it = arr[i].begin();it!=arr[i].end();it++)
        {
            cout<<*it<<"\t";
        }  
        cout<<endl;
    }
}
int FindstartIndex(vector<list<int>>arr)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i].size()!=0)
        {
            return i;
        }
    }
    return -1;
}
void BFS(vector<list<int>>arr,int n)
{
    vector<int>visited_arr(n,0);
    queue<int>q;
    int index = FindstartIndex(arr);
    q.push(index);
    visited_arr[index] = 1;
    while(!q.empty())
    {
        int CurrentIndex =  q.front();
        q.pop();
        cout<<CurrentIndex<<endl;
        for(auto it = arr[CurrentIndex].begin();it!=arr[CurrentIndex].end();it++)
        {
            if(visited_arr[*it] == 0)
            {
                q.push(*it);
                visited_arr[*it] = 1;
            }
        }
    }
}
int main()
{

    int n;
    cout<<"Enter the no of Vertices:"<<endl;
    cin>>n;
    vector<list<int>>arr = CreateGraph(n);
    //display(arr,n);
    BFS(arr,n);
    return(0);
}