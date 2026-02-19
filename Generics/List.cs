using System;
using System.Collections.Generic;
public class Program
{
    public static void Main(string[] args)
    {
        List<int> list = new List<int>();

        list.Add(1);
        list.AddRange(new List<int> {1,2,3});

        list.Insert(0,1);
        list.InsertRange(0, new List<int>{5,6,7});

        Console.Write("Values:");
        IEnumerator<int> et = list.GetEnumerator();
        while(et.MoveNext())
        {
             Console.Write($"{et.Current}");
        }
        Console.WriteLine();

        list.Remove(1);
        list.RemoveAll(x=>x == 1);
        list.RemoveAt(0);

        list.Contains(1);
        list.Find(x => x == 1);
        list.FindAll(x => x == 1);

        list.Sort();
        list.Reverse();

        foreach(var val in list)
        {
            Console.Write($"value:{val}");
        }

    }
}