//Graph Representation using the Array;
#include<iostream>
#include<vector>
using namespace std;
void createGraph(vector<vector<int>>&arr,int n)
{
    int value;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"Enter 1 if there is edge b/w"<<i<<j<<":\t";
            cin>>arr[i][j];
        }
    }
}
void display(vector<vector<int>>arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
int main()
{
    int n;
    cout<<"Enter the No of Vertices:"<<"\t";
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n,0));
    createGraph(arr,n);
    display(arr,n);

    return 0;
}