using System;
using System.Collections.Generic;
public class Program
{
    
    public static int MaxSumK(List<int> list,int k)
    {
        int i=0;
        int j=0;

        int n = list.Count;
        int sum = 0;
        int maxSum = 0;
        while(j<n)
        {
            //Expand The Window here
            while(j<n && (j-i+1) <= n)
            {
                sum += list[j];
                if(j-i+1 == k)
                {
                    Console.WriteLine($"{sum}");
                    maxSum = Math.Max(maxSum,sum);
                    break;
                }
                j++;
            }

            //Compress The Window Here
            sum -= list[i];
            i++;
            j++;
        }

        return maxSum;
    }
    
    public static int FindLongestSubArray(List<int> list,int sumK)
    {
        int i = 0;
        int j = 0;

        int sum = 0;

        int n = list.Count;

        int maxLen = 0;
        while(j<n)
        {
            
            //Expand Window
            while(j<n && sum <= sumK)
            {
                
                sum += list[j];
                if(sum > sumK)
                {
                    int len = j - i;
                    Console.WriteLine($"len:{len}");
                    maxLen = Math.Max(maxLen,len);
                    break;
                }
                j++;
            }

            //Compress Window
            sum -= list[i];
            i++;
            j++;
        }

        return maxLen;
    }
    

    public static List<int> FirstNegativeOfWindowOfSizeK(List<int> list,int k)
    {
        int i=0;
        int j=0;
        int lastIndex = 0;
        int n = list.Count;
        List<int>ans = new List<int>();
        
        while(j<n)
        {
            
            if(list[j] < 0)
            {
                
                while(i<=j)
                {
                    i++;
                    ans.Add(list[j]);
                }
                j++;

            }
            
            
            if(j - i + 1 == k)
            {
                i++;
                list.Add(int.MaxValue);
            }
            
            //ExpandWindow
            j++;
        }

        return ans;
    }


    public static void Main(string[] args)
    {
        
        Console.WriteLine($"MaxSumk:{MaxSumK(new List<int>(){1,2,3},2)}");

        Console.WriteLine($"longestsubArray:{FindLongestSubArray(new List<int>(){1,2,3},3)}");

        var ans = FirstNegativeOfWindowOfSizeK(new List<int>(){1,2,3,-1,-1,2,3,4,5},2);

        foreach(var val in ans)
        {
            Console.Write($"{val}\t");
        }
    }
}