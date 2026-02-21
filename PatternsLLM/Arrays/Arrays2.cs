using System;
using System.Collections.Generic;
public class Array2
{
    public static int MaxminumSubArray(List<int>list,int k)
    {
        int i=0;
        int sum = 0;
        while(i<k)
        {
            sum = sum + list[i];
            i = i + 1;
        }
        int j = k-1;
        i = 0;
        int maxSum = 0;
        maxSum = Math.Max(sum,maxSum);
            
        while(j+1<list.Count)
        {
            
            sum = sum - list[i];

            sum = sum + list[j+1];

            maxSum = Math.Max(sum,maxSum);

            i = i + 1;
            j = j + 1;    
        }
        return maxSum;
    }
    
    public static int LongestSubArray(List<int>list,int sumk)
    {
        int i=0;
        int j=0;
        int len = 0;
        int sum = 0;
        
        while(j<list.Count)
        {
            if(sum > sumk)
            {
                len = Math.Max(len,j-i);
                while(sum > sumk)
                {
                    i++;
                    sum = sum - list[i];
                }
            }
            sum = sum + list[j];
            j++;
        }
        return len;
    }
    public static void Display(List<int>arr)
    {
        Console.WriteLine("Array:\t");
        foreach(int val in arr)
        {
            Console.WriteLine($"{val}\t");
        }
        Console.WriteLine();
    }
    public static void FirstNegativeWindowSizeK(List<int>list,int k)
    {
        int i=0;
        int j =0;
        List<int>ans = new List<int>();
        List<int> indexList = new List<int>();

        while(j<k)
        {
            if(list[j] < 0)
            {
                indexList.Add(j);
            }
            j++;
        }

        while(j<list.Count)
        {
            if(indexList.Count > 0)
            {
                int index = indexList[0];

                if(i<=index && j>=index)
                {
                    ans.Add(list[index]);
                }
                else if(index <=i)
                {
                    indexList.RemoveAt(0);
                    continue;
                }
            }
            if( j+1 < list.Count && list[j+1] < 0)
            {
                indexList.Add(j+1);
            }
            j++;
            i++;
        }
        Display(ans);

    }

    public static void Main(string[] args)
    {
        
        Console.WriteLine($"MaximumSubarr:{MaxminumSubArray(new List<int>(){1,2,10,4,5},2)}");
        Console.WriteLine($"LongestSubArray:{LongestSubArray(new List<int>(){1,2,1,1,1},3)}");
        FirstNegativeWindowSizeK(new List<int>(){1,-1,-1,-1,-2,1,1,1,1},2);
        return;
    }

}