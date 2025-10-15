#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
vector<list<int>> createarr(int n)
{
    int temp;
    vector<list<int>>arr(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"Enter 1 if there is the edge b/w"<<i<<j<<":"<<endl;
            cin>>temp;
            if(temp == 1)
            {
                arr[i].push_back(j);
                temp = 0;
            }
        }
    }
    return arr;
}
void display(vector<list<int>>arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(auto it = arr[i].begin();it!=arr[i].end();it++)
        {
            cout<<*it<<"\t";
        }
        cout<<"\n";
    }
}
void DFS(vector<list<int>>arr,int n)
{
    stack<int>s;
    vector<int>visitedarr(n,0);
    s.push(0);
    visitedarr[0] = 1;
    while(!s.empty())
    {
        int CurrentElement = s.top();
        s.pop();
        cout<<CurrentElement<<endl;
        for(auto it = arr[CurrentElement].begin();it!=arr[CurrentElement].end();it++)
        {
            if(visitedarr[*it] == 0)
            {
                s.push(*it);
                visitedarr[*it] = 1;
            }
        }
    }
}
int main()
{

    int n;
    cin>>n;
    vector<list<int>>arr = createarr(n);
    display(arr,n);
    DFS(arr,n);
    return(0);
}