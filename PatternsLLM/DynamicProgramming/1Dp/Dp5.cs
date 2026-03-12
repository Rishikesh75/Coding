using System;
using System.Collections.Generic;

public class Program
{
    
    public static List<int> arr;

    public static void CreateArr()
    {
        arr = new List<int>(){1,2,3,4};

        return;
    }

    public static int MaxSum(int n)
    {
        
        if(n == 0)
            return arr[0];

        return Math.Max(MaxSum(n-1)+arr[n],arr[n]);
    }
    public static void Main(string[] args)
    {
        CreateArr();

        Console.WriteLine($"MaxSum:{MaxSum(arr.Count-1)}");

    }
}