#include<iostream>
#include<vector>
using namespace std;
int n;
vector<vector<int>>CreateBoard(int n)
{
    vector<vector<int>>arr(n,vector<int>(n,0));
    return arr;
}
void placediagnol_1(vector<vector<int>>&arr,int i,int j)
{
     while(i<n && j<n)
     {
        arr[i][j] = 1;
        i = i + 1;
        j = j + 1;
     }
     return;
}
void placediagnol_2(vector<vector<int>>&arr,int i,int j)
{
     while(i>=0 && j>=0)
     {
        arr[i][j] = 1;
        i = i - 1;
        j = j - 1;
     }
     return;
}
void placediagnol_3(vector<vector<int>>&arr,int i,int j)
{
     while(i>=0 && j<n)
     {
        arr[i][j] = 1;
        i = i - 1;
        j = j + 1;
     }
     return;
}
void placediagnol_4(vector<vector<int>>&arr,int i,int j)
{
     while(i<n && j>=0)
     {
        arr[i][j] = 1;
        i = i + 1;
        j = j - 1;
     }
     return;
}
void ModifyBoard(vector<vector<int>>&arr,int i,int column)
{
    for(int i=0;i<n;i++)
    {
        arr[i][column] = 1;
    }
    for(int j = 0;j<n;j++)
    {
        arr[i][j] = 1;
    }
    placediagnol_1(arr, i, column);
    placediagnol_2(arr, i, column);
    placediagnol_3(arr, i, column);
    placediagnol_4(arr, i, column);
    return;
}
void Placequeen(vector<vector<int>>&arr,int column)
{
    if(column == n)
    {
        cout<<"There is path"<<endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i][column] == 0)
        {
            vector<vector<int>>arr_temp  = arr;
            arr[i][column] = 1;
            ModifyBoard(arr,i,column);
            Placequeen(arr,column+1);
            arr = arr_temp;
        }
    }
    return;
}
int main()
{
    cout<<"Enter the value of N:"<<endl;
    cin>>n;
    vector<vector<int>>arr = CreateBoard(n);
    Placequeen(arr,0);
    return(0);
}