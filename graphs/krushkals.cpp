#include<iostream>
#include<vector>
#include<list>
using namespace std;
//(index,weight);
vector<list<pair<int,int>>> CreateArray(int n)
{
    vector<list<pair<int,int>>>arr(n);
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp=0;
            cout<<"Enter the Edge b/w("<<i<<","<<j<<")"<<endl;
            cin>>temp;
            if(temp == 1)
            {
                arr[i].push_back(make_pair(j,temp));
            }
        }
    }
    return arr;
}
void display(vector<list<pair<int,int>>>arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(auto it = arr[i].begin();it!=arr[i].end();it++)
        {
            cout<<it->first<<it->second<<"\t";
        }
        cout<<"\n";
    }
}

int main()
{
    int n;
    cin>>n;
    vector<list<pair<int,int>>>arr = CreateArray(n);
    display(arr,n);

    return 0;
}