#include<iostream>
#include<vector>
using namespace std;

vector<vector<char>> CreateArray(int n)
{
    vector<vector<char>>arr(n,vector<char>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    return arr;
}
void display(int n,vector<vector<char>>arr)
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
void Recurssion(string str,int i,int j,int currentindex,int length,vector<vector<char>>arr,int n)
{
    
    if(i<0 || j<0 || i>=n || j >=n)
    {
        return;
    }
    if(currentindex == length-1 && str[currentindex] == arr[i][j])
    {
        cout<<"Yes the string is Found";
        return;
    }
    
    if(arr[i][j] == str[currentindex])
    {
        Recurssion(str,i+1,j,currentindex+1,length,arr,n);
        Recurssion(str,i,j+1,currentindex+1,length,arr,n);
        Recurssion(str,i-1,j,currentindex+1,length,arr,n);
        Recurssion(str,i,j-1,currentindex+1,length,arr,n);
    }
    return;

}
void start(vector<vector<char>>arr,int n,string s)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j] == s[0])
            {
                Recurssion(s,i,j,0,s.length(),arr,n);
            }
        }
    }
}
int main()
{

    int n;
    cin>>n;
    vector<vector<char>>arr = CreateArray(n);
    display(n,arr);
    string str;
    cin>>str;
    start(arr,n,str);

    return(0);
}