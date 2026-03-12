using System;
using System.Collections.Generic;

public class Program
{
    
    public static List<(int StartTime,int EndTime)> CreateArr()
    {
        List<(int StartTime,int EndTime)> list = new List<(int StartTime, int EndTime)>()
        {
            (1,5),
            (2,4),
            (3,6),
            (5,7),
            (8,9),
            (5,9)
        };

        return list;
    }

    public static void Display(List<(int StartTime,int EndTime)> list)
    {
        Console.Write("Intervals:");

        foreach(var val in list)
        {
            Console.Write($"\t {val.StartTime} {val.EndTime}");
        }

        return;
    }
    public class  Comparator : IComparer<(int StartTime,int EndTime)>
    {
        public int Compare((int StartTime,int EndTime) x1,(int StartTime,int EndTime) x2)
        {
            return x1.StartTime.CompareTo(x2.StartTime);
        }
    }

    public static bool IsOverlapping((int StartTime,int EndTime) topInterval,(int StartTime,int EndTime) currInterval)
    {
        if(topInterval.EndTime > currInterval.StartTime)
        {
            return true;
        }

        return false;
    }
    public static List<(int StartTime,int EndTime)> MergeIntervals(List<(int StartTime,int EndTime)> list)
    {
        list.Sort(new Comparator());

        List<(int StartTime,int EndTime)> ans = new List<(int StartTime,int EndTime)>();

        ans.Add(list[0]);

        for(int i = 1; i < list.Count; i++)
        {
            var last = ans[ans.Count - 1];

            if(IsOverlapping(last, list[i]))
            {
                last.EndTime = Math.Max(last.EndTime, list[i].EndTime);
                ans[ans.Count - 1] = last;
            }
            else
            {
                ans.Add(list[i]);
            }
        }

        Console.WriteLine("Intervals After Merging:");
        Display(ans);

        return ans;
    }   
 public static void Main(string[] args)
    {
        var intervals = CreateArr();

        MergeIntervals(intervals);
    }
}