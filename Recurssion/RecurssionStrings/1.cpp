#include<iostream>
#include<vector>
#include<set>
using namespace std;
void FindMax(vector<int>arr,int index,int &maxvalue)
{
    if(index == 0)
    {
        maxvalue = arr[index];
        FindMax(arr,index+1,maxvalue);
        return;
    }
    else if(index == arr.size())
    {
        return;
    }
    maxvalue = max(arr[index],maxvalue);
    FindMax(arr,index+1,maxvalue);
    return;
}
int Linearsearch(vector<int>arr,int index,int value)
{   
    if(index == arr.size())
    {
        return -1;
    }
    if(arr[index] == value)
    {
        return index;
    }
    return Linearsearch(arr,index+1,value);
}
int BinarySearch(vector<int>arr,int start,int end,int value)
{
    int mid = start + (end -start)/2;
    if(start>end)
    {
        return -1;
    }
    if(arr[mid] == value)
    {
        return mid;
    }
    if(arr[mid]>value)
    {
        return BinarySearch(arr,start,mid-1,value);
    }
    else if(arr[mid]<value)
    {
        return BinarySearch(arr,mid+1,end,value);
    }
}
bool Checkarraysorted(vector<int>arr,int index)
{
    if(index == arr.size()-1)
    {
        return true;
    }
    if(arr[index]>arr[index+1])
    {
        return false;
    }
    return Checkarraysorted(arr,index+1);
}
void Reversearray(vector<int>&arr,int start,int end)
{
    if(start>=end)
    {
        return;
    }
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    Reversearray(arr,start+1,end-1);
    return;
}
void createarr(vector<int>&arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cin>>arr[i];
    }
    return;
}
void display(vector<int>arr)
{   
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
int count_occurance = 0;
void Countocurrnaces(string str,char c,int index)
{   
    if(index == str.length())
    {
        return;
    }
    if(str[index] == c)
    {
        count_occurance = count_occurance + 1;
    }
    Countocurrnaces(str,c,index+1);
}
void Replacealltheoccurances(string str,int index,char c)
{
    if(index == str.length())
    {
        return;
    }
    if(str[index] == c)
    {
        str[index] = '-';
    }
    Replacealltheoccurances(str,c,index+1);
}
set<char>s;
string ans;
void RemvoetheDuplciates(string str,int index)
{
    if(index == str.length())
    {
        return;
    }
    if(s.find(str[index]) == s.end())
    {
        ans.push_back(str[index]);
        s.insert(str[index]);
    }
    RemvoetheDuplciates(str,index+1);
}
int main()
{
    // int maxvalue;
    // int n;
    // cin>>n;
    // vector<int>arr(n);
    // createarr(arr);
    // FindMax(arr,0,maxvalue);
    // cout<<maxvalue<<endl;
    // int value;
    // cin>>value;
    // cout<<Linearsearch(arr,0,value)<<endl;
    // cout<<BinarySearch(arr,0,arr.size()-1,value)<<endl;
    // cout<<Checkarraysorted(arr,0)<<endl;
    // Reversearray(arr,0,arr.size()-1);
    // display(arr);
    string str;
    cin>>str;
    char c;
    cin>>c;
    Countocurrnaces(str,c,0);
    cout<<count_occurance<<endl;
    RemvoetheDuplciates(str,0);
    cout<<ans<<endl;
    return(0);

}