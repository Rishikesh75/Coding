using System;
using System.Collections.Generic;
public class Program
{
    public static (int StartIndex,int EndIndex) TwoSum(List<int>list,int sum)
    {
        int i=0;
        int j = list.Count-1;
        int startIndex = -1;
        int endIndex = -1;
        while(i<j)
        {
            if(list[i]+list[j]>sum)
            {
                j = j-1;
                continue;
            }
            else if(list[i]+list[j]<sum)
            {
                i = i + 1;
                continue;
            }
            else
            {
                startIndex = i;
                endIndex = j;
                break;
            }
        }

        return (startIndex,endIndex);

    }

    public static void ReverseArr(List<int>list)
    {
        int start = 0;
        int end = list.Count-1;

        while(start < end)
        {
            int temp = list[start];
            list[start] = list[end];
            list[end] = temp;

            start++;
            end--;
        }

        Display(list);
    }

    public static int ContainerWithMostWater(List<int>list)
    {
        int i=0;
        int j=list.Count-1;
        int volumne = 0;
        while(i<j)
        {
            volumne = Math.Max(volumne,(j-i+1)*Math.Min(list[i],list[j]));
            if(list[i] < list[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return volumne;
    }
    public static void Display(List<int> list)
    {
        Console.Write("Arr:");
        foreach(var val in list)
        {
            Console.Write($"{val}\t");
        }
        Console.WriteLine();
        return;
    }
    public static void Main(string[] args)
    {
        var ans = TwoSum(new List<int>(){1,2,3,4},5);
        Console.WriteLine($"Index1:{ans.StartIndex} Index2:{ans.EndIndex}");

        ReverseArr(new List<int>(){1,2,3});

        Console.WriteLine($"MaxVloume:{ContainerWithMostWater(new List<int>(){1,2,3,4,5})}");
        return;
    }
}