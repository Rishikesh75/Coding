#include<iostream>
#include<vector>
#include "array.h"
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
    missingNumber(arr_1,n_1);
    return(0);
}