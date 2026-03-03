using System;
using System.Collections.Generic;

public class Program
{
    
    public static bool BinarySearch(List<int> list ,int start,int end,int val)
    {
        
        if(start>end)
            return false;

        int mid = start + (end - start)/2;

        if(list[mid] == val)
            return true;
        
        if(list[mid] > val)
            return BinarySearch(list,start,mid-1,val);

        if(list[mid] < val)
            return BinarySearch(list,mid+1,end,val);

        return false;
    }


    public static void Main(string[] args)
    {
        List<int> list = new List<int>{1,2,3,5,4};
        list.Sort();

        Console.WriteLine(BinarySearch(list,0,list.Count-1,2));
    }
}