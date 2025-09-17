#include<iostream>
using namespace std;

void Recurssion(vector<int>arr,int i,int j,int n)
{
    if(i == n-1 && j == n-1)
    {
        cout<<"There is path"<<endl;
        return;
    }
    if(i>n || j > n)
    {
        return;
    }
    if(arr[i+1][j] == 1)
    {
        Recurssion(arr,i+1,j,n);
    }
    else if(arr[i][j+1] == 1)
    {
        Recurssion(arr,i,j+1,n);
    }
    return;
}
vector<vector<int>>arr Createarr(int n)
{
    vector<vector<int>>arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    return arr;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>arr = Createarr(n);
    Recurssion(arr,0,0,n);
    return(0);
}