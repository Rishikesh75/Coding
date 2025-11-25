//PowerSet
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void GenerateSets(vector<int>arr,int n)
{
    vector<vector<int>>ans;
    for(int i=0;i<pow(2,n);i++)
    {
        vector<int>subset;
        for(int j=0;j<n;j++)
        {
            if(i & (1 << j))
            {
                subset.push_back(arr[j]);
            }
        }
        ans.push_back(subset);
    }

    for(int i=0;i<ans.size();i++)
    {
        cout<<"Subset:\t";
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<"\t";
        }
        cout<<"\n";
    }

}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    GenerateSets(arr,n);
    return 0;
}