using System;
using System.Collections.Generic;

public class Program
{
    public static List<(int startTime, int endTime)> CreateActivities()
    {
        var list = new List<(int startTime, int endTime)>()
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

    public static void DisplayList(List<(int startTime, int endTime)> list)
    {
        foreach (var item in list)
        {
            Console.Write($"({item.startTime},{item.endTime}) \t");
        }
        Console.WriteLine();
    }

    public class Comparator : IComparer<(int startTime, int endTime)>
    {
        public int Compare((int startTime, int endTime) x1, (int startTime, int endTime) x2)
        {
            return x1.endTime.CompareTo(x2.endTime);
        }
    }

    public class Comparator2 : IComparer<(int startTime,int endTime)>
    {
        public int Compare((int startTime,int endTime) x1,(int startTime,int endTime) x2)
        {
            return x1.startTime.CompareTo(x2.startTime);
        }
    }

    public static List<(int startTime, int endTime)> SelectActivities(List<(int startTime, int endTime)> list)
    {
        list.Sort(new Comparator());

        Console.WriteLine("Sorted Activities (by end time):");
        DisplayList(list);

        List<(int startTime, int endTime)> result = new List<(int startTime, int endTime)>();

        result.Add(list[0]);
        int lastEndTime = list[0].endTime;

        int count = 0;

        for (int i = 1; i < list.Count; i++)
        {
            if (list[i].startTime >= lastEndTime)
            {
                result.Add(list[i]);
                lastEndTime = list[i].endTime;
            }
            else
            {
                count++;
            }
        }

        Console.WriteLine($"Min of Intervals to Remove: {count}");
        return result;
    }

    public static bool CheckPlatform(Dictionary<int,(int start,int end)> dict,(int startTime,int endTime) train,int count)
    {
        foreach(var item in dict)
        {
            var key = item.Key;
            var val = item.Value;

            if(train.startTime >= val.end)
            {
                dict[key] = train;
                return true;
            }
        }
        
        dict.Add(++count,train);
        return false;
    }

    public static int MinNoOfPlatforms(List<(int startTime, int endTime)> list)
    {
        list.Sort(new Comparator2());

        Console.WriteLine("Sorted Activities (by start time):");
        DisplayList(list);

        Dictionary<int,(int start,int end)> dict = new Dictionary<int, (int start,int end)>();

        dict.Add(1,(list[0].startTime,list[0].endTime));
        int count = 1;

        for(int i=1;i<list.Count;i++)
        {
            if(CheckPlatform(dict,list[i],count))
                continue;

            count++;
        }

        Console.WriteLine($"Min No Of Platforms: {count}");
        return count;
    }

    public static void Main(string[] args)
    {
        var activities = CreateActivities();

        Console.WriteLine("Original Activities:");
        DisplayList(activities);

        var selected = SelectActivities(activities);

        Console.WriteLine("\nSelected Activities (Maximum Non-Overlapping):");

        foreach (var val in selected)
        {
            Console.WriteLine($"{val.startTime} {val.endTime}");
        }

        MinNoOfPlatforms(activities);
    }
}