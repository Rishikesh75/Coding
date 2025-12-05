//Bfs array..
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void CreateGraph(vector<vector<int>>&arr,int n)
{
    int rowindex = 0;
    for(auto &row : arr)
    {
        int columnindex = 0;
        for(auto &value : row)
        {
            cout<<"Enter 1 if there is Edge from"<<rowindex<<columnindex;
            cin>>value;
            columnindex++;
        }
        rowindex++;
    }
    return;
}
void Display(vector<vector<int>>arr,int n)
{
    cout<<"Grap:\n";
    for(auto row : arr)
    {
        
        for(auto value : row)
        {
            cout<<value<<"\t";   
        }
        cout<<"\n";
        
    }
}
int Findstartindex(vector<vector<int>>Graph)
{
    int rowindex = 0;
    for(auto row : Graph)
    {
        for(auto value : row)
        {
            if(value == 1)
            {
                return rowindex;
            }
        }
        rowindex++;
    }
    return -1;
}
void Bfs(vector<vector<int>>Graph,int n)
{
    cout<<"BFS:\t";
    queue<int>q;
    vector<int>visited_arr(n,0);
    int start_index = Findstartindex(Graph);
    if(start_index == -1) return;
    q.push(start_index);
    visited_arr[start_index] = 1;
    while(!q.empty())
    {
        int temp = q.front();
        cout<<temp<<" ";
        q.pop();
        for(int i=0;i<Graph[temp].size();i++)
        {
            if(visited_arr[i] == 0)
            {
                q.push(i);
                visited_arr[i] = 1;
            }
        }
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>Graph(n,vector<int>(n,0));
    CreateGraph(Graph,n);
    Display(Graph,n);
    Bfs(Graph,n);
    return 0;
}