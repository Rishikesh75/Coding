using System;
using System.Collections.Generic;

public class Program
{
    
    public static List<int> Hb;
    public static List<int>dp;
    public static void CreateHouseRobber()
    {
        Hb =  new List<int>(){1,2,3};
    }

    public static void CreateDp()
    {
        dp = Enumerable.Repeat(-1,Hb.Count).ToList();
    }
    public static void Display(List<int> arr)
    {
        
        foreach(var val in arr)
        {
            Console.Write($"{val}\t");
        }

        Console.WriteLine();
    }

    public static int HouseRobber(int n)
    {
        if(n == 0)
            return Hb[0]; 

        if(n == 1)
            return Math.Max(Hb[0],Hb[1]);


        return Math.Max(HouseRobber(n-2) +  Hb[n],HouseRobber(n-1));       
    }

    public static int HoubeRobberTopDown(int n)
    {
        if(n == 0)
            return Hb[0];

        if(n == 1)
            return Math.Max(Hb[0],Hb[1]);
        
        if(dp[n] != -1)
            return dp[n];

        dp[n] = Math.Max(HoubeRobberTopDown(n-2) + Hb[n],HoubeRobberTopDown(n-1));

        return dp[n];
    }

    public static int HouseRobberBottomUp(int n)
    {
        CreateDp();
        
        if(n == 0)
            return Hb[0];
        if(n == 1)
            return Math.Max(Hb[0],Hb[1]);
        
        dp[0] = Hb[0];
        dp[1] = Math.Max(Hb[0],Hb[1]);

        for(int i=2;i<=n;i++)
        {
            dp[i] = Math.Max(HoubeRobberTopDown(i-2) + Hb[n],HoubeRobberTopDown(i-1));
        }

        return dp[n];
    }

    public static void Main(string[] args)
    {
        CreateHouseRobber();

        Console.WriteLine($"HoubeRobber(Recurssion):{HouseRobber(Hb.Count-1)}");

        CreateDp();

        Console.WriteLine($"HouseRobber(TopDown):{HoubeRobberTopDown(Hb.Count-1)}");

        Console.WriteLine($"HouseRobber(BottomUp):{HouseRobberBottomUp(Hb.Count-1)}");
        return;
    }


}