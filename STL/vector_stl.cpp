#include<iostream>
#include<vector>
using namespace std;

void create_arr(vector<int>&arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
void displayarr(vector<int>arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}

int main()
{
    // int n;
    // cin>>n;
    // vector<int>arr(n,0);
    // arr.erase(arr.begin(),arr.begin()+4);
    // arr.insert(arr.begin(),5);
    // arr.pop_back();
    // arr.push_back(4);
    // arr.clear();
    // arr.empty();
    // return(0);
    int n;
    cin>>n;
    vector<int>arr(n,0);
    displayarr(arr,n);
    arr.erase(arr.begin(),arr.begin()+1);
    arr.insert(arr.begin(),2);
    arr.pop_back();
    arr.push_back(4);
    displayarr(arr,n);
    arr.clear();
}