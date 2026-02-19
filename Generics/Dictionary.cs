using System;
using System.Collections.Generic;
public class Program
{
    public static void Main(string[] args)
    {
        Dictionary<int,int> dict = new();

        dict.Add(1,1);

        dict.ContainsKey(1);

        dict.Remove(1);

        int val = dict.Count;

        foreach(var kvp in dict)
        {
            Console.WriteLine($"{kvp.Key} {kvp.Value}");
        }


    }

}