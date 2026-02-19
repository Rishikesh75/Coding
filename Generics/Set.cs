using System;
using System.Collections.Generic;
public class Program
{
    public static void Main(string[] args)
    {
        
        HashSet<int> set = new HashSet<int>();

        set.Add(1);
        set.Add(2);

        Console.WriteLine($"{set.Contains(1)}");

        set.Remove(1);


        set.UnionWith(new HashSet<int>(){1});
        set.IntersectWith(new HashSet<int>(){1});
        set.ExceptWith(new HashSet<int>(){1});

        set.IsSubsetOf(new HashSet<int>(){1});
        set.IsSupersetOf(new HashSet<int>(){1});

        set.SetEquals(new HashSet<int>(){1,2});


        return;
    }
}