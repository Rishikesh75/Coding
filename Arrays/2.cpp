#include<iostream>
#include "array.h"
using namespace std;
void palce_row_zero()
{
}
void palce_column_zero()
{
    
}
void SetMatrixZero(vector<vector<int>>arr,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j = 0;i<n;j++)
        {
            if(arr[i][j] == 1)
            {
                arr[i][j] = 0;
                arr[i][0] = 1;
                arr[0][j]  = 1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i][0] == 1)
        {
            place_row_zero(arr,i,n);
        }
    }
    for(int j=0;j<m;j++)
    {
        if(arr[0][m] == 1)
        {
            place_column_zero(arr,j,m);
        }
    }
}
int main()
{
    TwoDArray arrayObj;
    int n;
    int m;
    cin>>n;
    cin>>m;
    vector<vector<int>>arr = arrayObj.createArray(n,m);


    return(0);
}