#include<iostream>
#include<vector>
using namespace std;
vector<int>arr;
void createarr(int n)
{
    arr.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
void swap(int i,int j)
{
    int value = arr[i];
    arr[i] = arr[j];
    arr[j] = value;
}
vector<vector<int>>ans;
void displayans()
{
    
    for(int i=0;i<ans.size();i++)
    {
        cout<<"Arr:\t";
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<"\t";
        }
         cout<<"\n";
    }
   
}
void f(int i_1,int i_2,int n)
{
    // cout<<i_1<<i_2<<endl;
    if(i_1 == n-1)
    {
        ans.push_back(arr);
        return;
    }
    if(i_1!=-1)
    {
        swap(i_1,i_2);
    }
    for(int j =i_1 + 1;j<n;j++)
    {
        f(i_1 + 1,j,n);
    }
    if(i_1!=-1)
    {
        swap(i_1,i_2);
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    createarr(n);
    f(-1,-1,n);
    displayans();
    return 0;
}