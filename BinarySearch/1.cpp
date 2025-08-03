#include<iostream>
#include<vector>
using namespace std;
vector<int> createarray(int n)
{
    vector<int>arr;
    int temp;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the Arr value:";
        cin>>temp;
        cout<<"\n";
        arr.push_back(temp);
    }
    return arr;
}
int BinarySearch(vector<int>arr,int target)
{
    int start = 0;
    int end = arr.size()-1;
    bool value;
    while(start<=end)
    {
        int mid  =start + (end-start)/2;
        if(arr[mid] == target)
        {
            start = mid;
            value = true;
            break;
        }
        else if(start == end)
        {
            start = -1;
            value = false;
            break;
        }
        else if(arr[mid] > target)
        {
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return start;
}
int LowerBound(vector<int>arr,int target)
{
    int start = 0;
    int end = arr.size()-1;
    while(start<end)
    {
        int mid =start + (end-start)/2;
        if(start+1== end)
        {
            if(arr[end]<=target)
            {
                return end;
            }
            else 
            {
                return start;
            }
        }
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid]>target)
        {
            end = mid -1;
        }
        else
        {
            start  =mid;
        }
    }
}
int UpperBound(vector<int>arr,int target)
{
    int start = 0;
    int end  =arr.size()-1;
    while(start<end)
    {
        int mid = start + (end-start)/2;
        if(start+1 == end)
        {
            if(arr[start]>=target)
            {
                return start;
            }
            else 
            {
                return end;
            }

        }
        if(arr[mid]==target)
        {   
            return mid;
        }
        else if(arr[mid]>target)
        {
            end = mid;
        }
        else{
            start = mid + 1;
        }
    }
}
int FindInsertpos(vector<int>arr,int target)
{
    int start = 0;
    int end = arr.size()-1;
    while(start<end)
    {
        int mid = start + (end-start)/2;
        if(start == end)
        {
            return start;
        }
        if(start+1 == end)
        {
            if(arr[start]<target)
            {
                return end;
            }
            return start;
        }
        if(arr[mid]>target)
        {
            end = mid;
        }
        else if(arr[mid]<target)
        {
            start = mid;
        }
    }
}
int findfirstoccurance(vector<int>arr,int target)
{
    int start = 0;
    int end = arr.size()-1;
    int Occurance = -1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(start==end)
        {
            if(arr[start] == target)
            {
                Occurance = mid;
            }
            break;
        }
        else if(arr[mid] == target)
        {
            Occurance = mid;
            end = mid-1;
        }
        else if(arr[mid]>target)
        {
            end = mid - 1;
        }
        else 
        {
            start = mid+1;
        }
        
    }
    return Occurance;
}
int findlastOccurances(vector<int>arr,int target)
{
    int start = 0;
    int end = arr.size()-1;
    int Occurance = -1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(start==end)
        {
            if(arr[start] == target)
            {
                Occurance = mid;
            }
            break;
        }
        else if(arr[mid] == target)
        {
            Occurance = mid;
            start = mid+1;
        }
        else if(arr[mid]>target)
        {
            end = mid - 1;
        }
        else 
        {
            start = mid+1;
        }
        
    }
    return Occurance;
}
int FindElementinrotatedSortedArr(vector<int>arr,int target)
{
    int start = 0;
    int end = arr.size()-1;
    while(start<=end)
    {
        int mid = start+(end-start)/2;

        if(arr[mid] == target)
        {
            return mid;
        }
        else if(start == end)
        {
            return -1;
        }
        else if(arr[mid]>target)
        {
            if(arr[start]>target)
            {
                start= mid + 1;
            }
            else 
            {
                end = mid - 1;
            }
        }
        else if(arr[mid]<target)
        {
            if(arr[end]>=target)
            {
                start =  mid + 1;
            }
            else 
            {
                end = mid - 1;
            }
        }
    }
}
int FindPeekElement(vector<int>arr)
{
    int start = 0;
    int end = arr.size()-1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
        {
            return mid;
        }
        else if(start == end)
        {
            return -1;
        }
        else if(arr[mid]>arr[mid-1] &&arr[mid]<arr[mid+1])
        {
            start = mid + 1;
        }
    }
}
int Findsqrt()
{
    int target;
    cout<<"Enter the Target Value:";
    cin>>target;
    int start = 0;
    int end = target;
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        if(mid*mid == target)
        {
            return mid;
        }
        else if(start == end)
        {
            return -1;
        }
        else if(mid*mid >target)
        {
            end = mid - 1;
        }
        else if(mid*mid<target)
        {
            start = mid + 1;
        }
    }
}
int NthPower(int value,int n)
{
    int temp = 1;
    for(int i=0;i<n;i++)
    {
        temp = temp * value;
    }
    return temp;
}
int FindNthRoot()
{
    int target;
    cout<<"Enter the Target Value:";
    cin>>target;
    int n;
    cout<<"Enter the Nth Root value:";
    cin>>n;
    int start = 0;
    int end = target;
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        if(NthPower(mid,n) == target)
        {
            return mid;
        }
        else if(start == end)
        {
            return -1;
        }
        else if(NthPower(mid,n) >target)
        {
            end = mid - 1;
        }
        else if(NthPower(mid,n)<target)
        {
            start = mid + 1;
        }
    }
}
int FindMax(vector<int>piles)
{
    int value = piles[0];
    for(int i=1;i<piles.size();i++)
    {
        if(piles[i]>value)
        {
            value = piles[i];
        }
    }
    return value;
}
int findtime(vector<int>piles,int mid)
{
    int time = 0;
    for(int i=0;i<piles.size();i++)
    {
        time = time + piles[i]/mid;
        if(piles[i]%mid!=0)
        {
            time = time + 1;
        }
    }
    return time;
}
int minhours(vector<int>piles,int hour)
{
    int start = 1;
    int end = FindMax(piles);
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        int time = findtime(piles,mid);
        if(time == hour)
        {
            return mid;
        }
        else if(time>hour)
        {
            start = mid + 1;
        }
        else if(time<hour)
        {
            end = mid - 1;
        }
    }
}
int main()
{
    int n,target;
    cout<<"Enter the Size fo array:";
    cin>>n;
    vector<int>arr = createarray(n);
    // cout<<"Enter the Value To search:"<<"\t";
    // cin>>target;
    // int ans =BinarySearch(arr,target); 
    // cout<<"Index:"<<ans<<endl;
    // int index = LowerBound(arr,target);
    // cout<<"LowerBound value:"<<arr[index]<<endl;
    // index =  UpperBound(arr,target);
    // cout<<"UpperBound Value:"<<arr[index]<<endl;
    // // index = FindInsertpos(arr,target);
    // // cout<<"Pos To Insert:"<<index<<endl;
    // index = findfirstoccurance(arr,target);
    // cout<<"First Occurances:"<<index<<endl;
    // index = findlastOccurances(arr,target);
    // cout<<"Last Occurances:"<<index<<endl;
    // int index = FindElementinrotatedSortedArr(arr,target);
    // cout<<"Index:"<<FindElementinrotatedSortedArr(arr,target)<<endl;
    // int peekIndex = FindPeekElement(arr);
    // cout<<"Peek Element is:"<<arr[peekIndex]<<endl;
    // int value = FindNthRoot();
    // cout<<"Nth Root Value:"<<value<<endl;
    cout<<"Enter the Target Value:"<<endl;
    cin>>target;
    int speed = minhours(arr,target);
    cout<<"Speed:"<<speed<<endl;

    return 0;
}