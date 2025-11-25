//Single Number - 1
#include<iostream>
#include<vector>
using namespace std;
int SingleNumber(vector<int>ans)
{
    int temp = ans[0];
    for(int i =1;i<ans.size();i++)
    {
        temp = temp ^ ans[i];
    }
    return temp;
}
int main()
{
    int n;
    cin>>n;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<SingleNumber(nums)<<endl;

    return 0;
}