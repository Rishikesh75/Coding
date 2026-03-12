using System;
using System.Collections.Generic;

public class Program
{

    public static List<int> CostArr;
    public static List<int> dp;
    public static void CreateCost()
    {
        CostArr = new List<int>(){1,2,3,4};

        return;
    }

    public static void CreateDp()
    {
        dp = Enumerable.Repeat(-1,CostArr.Count).ToList();
    }

    public static int MinCost(int n)
    {
        if(n == 0)
            return CostArr[0];

        if(n == 1)
            return Math.Min(CostArr[0]+CostArr[1],CostArr[1]);

        return  CostArr[n] + Math.Min(MinCost(n-1),MinCost(n-2));        
    }

    public static int MinCostTopDown(int n)
    {
        if(n == 0)
            return CostArr[0];

        if(n == 1)
            return Math.Min(CostArr[0]+CostArr[1],CostArr[1]);

        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = CostArr[n] + Math.Min(MinCost(n-1),MinCost(n-2));   

        return dp[n];
    }

    public static int MinCostBottomUp(int n)
    {
        CreateDp();

        if(n == 0)
            return CostArr[0];

        if(n == 1)
            return Math.Min(CostArr[0]+CostArr[1],CostArr[1]);

        dp[0] = CostArr[0];
        dp[1] = Math.Min(CostArr[0]+CostArr[1],CostArr[1]);

        for(int i=2;i<=n;i++)
        {
            dp[i] = CostArr[n] + Math.Min(dp[i-1],dp[i-2]);
        }

        return dp[n];
    }

    public static void Main(string[] args)
    {

        CreateCost();   
        Console.WriteLine($"MinCost:{MinCost(CostArr.Count-1)}");

        CreateDp();
        Console.WriteLine($"MinCostTopDown:{MinCostTopDown(CostArr.Count-1)}");

        Console.WriteLine($"MinCostBottomUp:{MinCostBottomUp(CostArr.Count-1)}");
        
        return;
    }
}