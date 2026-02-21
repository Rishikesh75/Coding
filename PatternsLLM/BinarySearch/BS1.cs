using System;
using System.Collections.Generic;
public class Progarm
{
    public static bool BinarySearch(List<int>arr,int start,int end,int val)
    {
        if(start>end) 
            return false;
        
        int mid = start + (end -  start)/2;
        
        if(arr[mid] == val)
            return true;
        
        else if(arr[mid]>val)
            return BinarySearch(arr,start,mid-1,val);
        else
            return BinarySearch(arr,mid+1,end,val);

    }
    
    public static void Main(string[] args)
    {
        var list = new List<int>(){1,2,3,4,5};
        bool val = BinarySearch(list,0,list.Count-1,2);
        Console.WriteLine($"BianrySearch:{val}");
    }
}