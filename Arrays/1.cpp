#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include "array.h"
#include "Math.h"
using namespace std;
pair<int,int>largestElementArray(int n,vector<int>arr)
{
    pair<int,int>temp;
    temp.first = 0;
    temp.second = arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>temp.second)
        {
            temp.first =i;
            temp.second = arr[i];
        }
    }
    return temp;
}
pair<int,int>secondLargestElement(int n,vector<int>arr)
{
    pair<int,int>temp_second_highest;
    temp_second_highest.first = -1;
    temp_second_highest.second =-1;
    pair<int,int> firsthighest;
    for(int i=0;i<n;i++)
    {
        if(i == 0)
        {
            firsthighest.second =arr[0];
            firsthighest.first = i;
        }
        else if(arr[i]!=firsthighest.second && temp_second_highest.first == -1)
        {
            if(arr[i]>firsthighest.second)
            {
                temp_second_highest.second = firsthighest.second;
                temp_second_highest.first = firsthighest.first;
                firsthighest.second = arr[i];
                firsthighest.first = i;
            }
            else if(arr[i]<firsthighest.second)
            {
                temp_second_highest.second = arr[i];
                temp_second_highest.first = i;
            }
            else
            {
                continue;
            }
        }
        else
        {
            if(arr[i]>firsthighest.second)
            {
                temp_second_highest.second = firsthighest.second;
                temp_second_highest.first = firsthighest.first;
                firsthighest.second = arr[i];
                firsthighest.first = i;
            }
            else if(arr[i]<firsthighest.second && arr[i]>temp_second_highest.second)
            {
                temp_second_highest.second = arr[i];
                temp_second_highest.first = i;
            }
        }
    }
    return temp_second_highest;
}
bool check_array_sorted(int n,vector<int>arr)
{
    bool isSorted = true;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[i+1])
        {
            isSorted = false;
        }
    }
    return isSorted;
}
void swap(vector<int>&arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void removeDuplicateSortedArray(int n,vector<int>arr)
{
    int i=0;
    int j=1;
    int last_index = i;
    while(1)
    {
        if(j == n)
        {
            break;
        }
        if(arr[i] == arr[j])
        {
            j = j + 1;
        }
        else if(arr[i]!=arr[j])
        {
            swap(arr,i+1,j);
            i = i +1;
            j = j+1;
            last_index = i;
        }
    }
    Array arrObject;
    arrObject.displayArr(last_index,arr);
}
void leftRotateArray(int n,vector<int>arr,int places)
{
    vector<int>temp(places,0);
    Array arrayObj;
    arrayObj.copyArr(places,arr,temp,0);
    for(int i=0;i<n-places;i++)
    {
        arr[i] = arr[i+places];
    }
    for(int i=n-places;i<n;i++)
    {
        arr[i] = temp[i -(n-places)];
    }
    arrayObj.displayArr(n-1,arr);
}

void MoveZeroes(vector<int>&arr,int n)
{
    Array arrObj;
    int i=0;
    int j=0;
    while(1)
    {
        if(i == n)
        {
            break;
        }
        if(arr[i]!=0)
        {
            i= i+1;
            j = j + 1;
        }
        else if(arr[i] == 0)
        {
            while(1)
            {
                if(arr[j]!=0 || j == n)
                {
                    break;
                }
                if(arr[j] == 0)
                {
                    j = j + 1;
                }
            }
            if(arr[j] != 0 && j!=n)
            {
                arrObj.arrSwap(arr,i,j);
            }   
            i = j;
        }
    }
}
int LinearSearch(vector<int>arr,int n,int num)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}
void UnionArray(vector<int>arr_1,vector<int>arr_2,int n_1,int n_2)
{
    Array ArrObj;
    int i_1 = 0;
    int i_2 = 0;
    while(1)
    {
        if(i_1 == n_1)
        {
            break;
        }
        if(arr_1[i_1]>arr_2[i_2])
        {
            ArrObj.arrSwap(arr_1,arr_2,i_1,i_2);
            ArrObj.arrCheck(arr_2,n_2);
        }
        i_1 = i_1 + 1;
    }
    ArrObj.displayArr(n_1-1,arr_1);
    ArrObj.displayArr(n_2-1,arr_2);
}
void missingNumber(vector<int>arr,int n)
{
    //Optimal Approch
    int temp;
    for(int i=0;i<=n;i++)
    {
        if(i == 0)
        {
            temp = arr[i] ^ i+1;
        }
        else if(i == n)
        {
            temp = temp ^ i+1;
        }
        else
        {
            temp = temp ^ arr[i] ^ i+1;
        }

    }
    cout<<"Missing Number:"<<temp<<endl;
}

int maxConsecutiveOnes(vector<int>arr,int n)
{
    
    int count=0;
    int maxCount =0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 1)
        {
            count = count  + 1;
        }
        else
        {
            maxCount = max(maxCount,count);
            count = 0;
        }
    }
    cout<<count<<maxCount<<endl;
    maxCount = max(maxCount,count);
    cout<<"Max Consecutive ones in the array"<<maxCount<<endl;
}
void NumberApperingOnce(int n,vector<int>arr)
{
    int temp = arr[0];
    for(int i=1;i<n;i++)
    {
        temp = arr[i] ^ temp;
    }
    cout<<"Number Appering Once:"<<temp<<endl;
}
//STILL NEED TO BE CORRECTED
int LongestSumKInArray_BruteForce(int n,vector<int>arr)
{
    int sum = 0;
    int max_sum;
    pair<int,int>temp;
    bool exist = false;
    int k;
    cout<<"Enter the sum:\t";
    cin>>k;
    for(int i=0;i<n;i++)
    {
        for(int j = i;j<n;j++)
        {
            sum = sum  + arr[j];
            if(sum == k)
            {
                exist = true;
                if(temp.first == -1 && temp.second == -1)
                {
                    temp.first = i;
                    temp.second = j;
                }
                else if(temp.second -  temp.first < j - i)
                {
                    temp.first = i;
                    temp.second = j;
                }
                
            }
        }
        sum = 0;
    }
    if(exist == true)
    {
        cout<<"start index:"<<temp.first<<"second index:"<<temp.second<<endl;
    }
    else
    {
        cout<<"Max sum in the sumb array is:"<<max_sum<<endl;
        cout<<"start index:"<<-1<<"second index:"<<-1<<endl;
    }
    
}
int LongestSumKInArrayOptimizedApproch(int n,vector<int>arr)
{
    int k;
    cout << "Enter the Sum: ";
    cin >> k;
    pair<int,int>temp;
    temp.first = -1;
    temp.second = -1;
    int sum = 0;
    map<int, int> IndexSum;
    IndexSum.insert({0, -1});
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        IndexSum.insert({sum, i}); // correct syntax
    }
    sum = 0;
    for (const auto& value : IndexSum) {
        cout << "Sum: " << value.first << ", Index: " << value.second << endl;
    }
    for(int i=0;i<n;i++)
    {
        sum = sum + arr[i];
        if(IndexSum.find(sum-k)!=IndexSum.end())
        {
            if(i - (IndexSum[sum-k] + 1)>temp.second - temp.first)
            {
                temp.first = IndexSum[sum-k] + 1;
                temp.second = i;
            }
           
        }
    }
    if(temp.first == -1 && temp.second == -1)
    {
        cout<<"Sum Not found in the array"<<endl;
    }
    else
    {
        cout<<"start Index:"<<temp.first<<"End Index:"<<temp.second<<endl;
    }
    
}
void TwoSumBruteForce(vector<int>arr,int n)
{
    int sum;
    cin>>sum;
    pair<int,int>temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {   
            if(arr[i]+arr[j] == sum)
            {
                temp.first = i;
                temp.second = j;
            }
        }
    }
    cout<<temp.first<<temp.second<<endl;
}
void TwoSumBetterApproch(vector<int>arr,int n)
{
    int sum;
    cin>>sum;
    map<int,int>HashMap;
    pair<int,int>temp;
    for(int i=0;i<n;i++)
    {
        HashMap.insert({arr[i],i+1});
    }
    for(int i=0;i<n;i++)
    {   
        if(HashMap[sum - arr[i]] != 0)
        {
            temp.first = i;
            temp.second = HashMap[sum - arr[i]];
        } 
    }
    cout<<temp.first<<temp.second<<endl;
}
void TwoSumOptimalAdpproch(vector<int>arr,int n)
{
    int sum;
    cin>>sum;
    sort(arr.begin(),arr.end());
    int i=0;
    int j = n-1;
    pair<int,int>temp;
    temp.first = -1;
    temp.second = -1;
    while(1)
    {
        if(i == j || j > i)
        {
            break;
        }
        if(arr[i]+arr[j] == sum)
        {
            temp.first = i;
            temp.second = j;
            break;
        }
        else if(arr[i]+arr[j]>sum)
        {
            j = j - 1;
        }
        else if(arr[i]+arr[j]<sum)
        {
            i = i + 1;
        }
    }
    cout<<"Index are"<<temp.first<<temp.second<<endl;
}
void sort_arrays_012(vector<int>arr,int n)
{
    int count_0 = 0,count_1 = 0,count_2 = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0)
        {
            count_0 = count_0 + 1;
        }
        else if(arr[i] == 1)
        {
            count_1 = count_1 + 1;
        }
        else
        {
            count_2 = count_2 + 1;
        }
    }
    int i=0;
    while(i!=n)
    {
        if(count_0 !=0)
        {
            arr[i] = 0;
            continue;
        }
        else if(count_1!=0)
        {
            arr[i] = 1;
            continue;
        }
        else
        {
            arr[i] = 2;
            continue;
        }
        i = i +1;
    }
    Array arrObj;
    arrObj.displayArr(n,arr);
}
void sort_arr_012(vector<int>arr,int n)
{
    sort(arr.begin(),arr.end());
    Array arrObj;
    arrObj.displayArr(n-1,arr);
}

void sortDutchNationalsAlgo(vector<int>arr,int n)
{
    Array arrObj;
    int low = 0;//First Ocuurance of 1
    int mid = 0;//Last occurance of 1 after
    int high = n-1;//Frist Ocurrance of 2 before
    while(mid<=high)
    {
        if(arr[low] == 0)
        {
            arrObj.arrSwap(arr,low,mid);
            low = low + 1;
            mid = mid +1 ;
        }
        else if(arr[mid] == 1)
        {
            mid = mid +1;
        }
        else if(arr[mid] == 2)
        {
            swap(arr,mid,high);
            high = high - 1;
        }
    }
    
    arrObj.displayArr(n-1,arr);
}
void MajorityElement(vector<int>arr,int n )
{
    int count =0;
    int num = arr[0];
    count = count + 1;
    for(int i=1;i<n;i++)
    {
        if(arr[i] == num && count!=0)
        {
            count = count  + 1;
        }
        else if(arr[i]!=num && count!=0)
        {
            count = count - 1;
        }
        else if(count == 0)
        {
            num = arr[i];
            count = count + 1;
        }
    }
    if(count>0)
    {
        cout<<"Element is:"<<num<<endl;
    }
    else
    {
        cout<<"Element Doesn't Exist"<<endl;
    }
}
void MaxSum(vector<int>arr,int n)
{
    //Kandesn Algoritham(Updation to the Problem Find the Index as well Here)
    int currentSum=0;
    int maxSum=0;
    int firstPostive = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0 && firstPostive == 0)
        {
            continue;
        }
        else if(arr[i]>0 && firstPostive == 0)
        {
            firstPostive = 1;
            currentSum = currentSum + arr[i];
            maxSum = max(currentSum,maxSum);
        }
    }
    cout<<"Max Sum in the Array:"<<maxSum<<endl;
}
void BuySellStock(vector<int>arr,int n)
{
    int sell = n-1;
    int buy = n-2;
    int profit = 0;
    int maxProfit = 0;
    while(buy!=-1)
    {
        if(arr[buy]>arr[sell])
        {
            sell = buy;
        }
        else
        {   
            profit = arr[sell] - arr[buy];
            maxProfit = max(profit,maxProfit);
        }
        buy = buy -1;
    }
    cout<<"Max Profit:"<<maxProfit<<endl;
}
void RearrangeArray(vector<int>arr,int n)
{
    vector<int>ans(n,0);
    int even_index = 0;
    int odd_index = 1;
    for(int i=0;i<n;i++)
    {   
        if(arr[i]%2 == 0)
        {
            ans[even_index] = arr[i];
            even_index = even_index + 2;
        }
        else
        {
            ans[odd_index] = arr[i];
            odd_index = odd_index + 2;
        }
    }
}
void swap(vector<int>arr,int i,int j,int n)
{
    Array arrObj;
    if(i == n-1)
    {
        arrObj.displayArr(n,arr);
        return ;
    }
    else if(i!=-1)
    {
        int temp =arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    for(int j = i + 1;i<n;i++)
    {
        swap(arr,i+1,j,n);
    }
}
void FindLeadersInArray(vector<int>arr,int n)
{
    Array arrObj;
    vector<int>LeadersArray;
    LeadersArray.push_back(arr[n-1]);
    int max = arr[n-1];
    for(int i=n-2;i>=0;i++)
    {
        if(arr[i]>max)
        {
            LeadersArray.push_back(arr[i]);
            max = arr[i];
        }
    }
    arrObj.displayArr(LeadersArray.size()-1,LeadersArray);
}
void FindLongestSequence(vector<int>arr,int n)
{
    sort(arr.begin(),arr.end());
    int i=0;
    int j = i + 1;
    int max_len = 0;
    int len = 1;
    while(j!=n)
    {
        if(arr[i] == arr[j])
        {
            j = j + 1;
        }
        else if(arr[j] = arr[i]+1)
        {
            len = len +1;
            max_len = max(max_len,len);
        }
        else 
        {
            len = 1;
            arr[i] = arr[j];
            j = j + 1;
        }
    }
    cout<<"Max_len"<<max_len<<endl;
}
int main()
{
    int n_1;
    cin>>n_1;
    // int n_2;
    // cin>>n_2;
    Array arrObject;
    vector<int>arr_1 = arrObject.createArray(n_1);
    // vector<int>arr_2 = arrObject.createArray(n_2);
    // pair<int,int>temp = largestElementArray(n,arr);
    // cout<<"Largest Element is:"<<temp.second<<" Index:"<<temp.first<<endl;
    // pair<int,int>temp_sec = secondLargestElement(n,arr);
    // cout<<"Second Largest Element is:"<<temp_sec.second<<"Index:"<<temp_sec.first<<endl;
    // cout<<"Array is Sorted:"<<check_array_sorted(n,arr)<<endl;
    // removeDuplicateSortedArray(n,arr);
    // leftRotateArray(n,arr,2);
    //MoveZeroes(arr,n);
    //arrObject.displayArr(n-1,arr);
    //UnionArray(arr_1,arr_2,n_1,n_2);
    // missingNumber(arr_1,n_1-1);
    //maxConsecutiveOnes(arr_1,n_1);
    //NumberApperingOnce(n_1,arr_1);
     //LongestSumKInArrayOptimizedApproch(n_1,arr_1);
    BuySellStock(arr_1,n_1);
    return(0);
}