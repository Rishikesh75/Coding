#include<iostream>
#include<vector>
using namespace std;

set<int>subset;
vector<vector<int>>subsets;
void Recurssion(vector<int>arr,int index)
{   
    if(index == n)
    {
        subsets.push_back(subset);
        return;
    }
    subset.push_back(arr[index]);
    recurssion(arr,index+1);
    subset.pop_back();
    recurssion(arr,index+1);
}

int main()
{

    return(0);
}