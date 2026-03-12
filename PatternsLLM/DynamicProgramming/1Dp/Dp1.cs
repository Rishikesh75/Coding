//Climbing Staris
using System;
using System.Collections.Generic;

public class Program
{
    public static void CreateDp(int n)
    {
        dp = Enumerable.Repeat(-1,n+1).ToList();
    }
    public static List<int> dp;
    public static int ClimbStairs(int n)
    {
        if(n<=2)
            return n-1;
            
        return ClimbStairs(n-1) + ClimbStairs(n-2);
    }

    public static int ClimbStairsTopDown(int n)
    {
        if(n<=2)
            return n-1;
        
        if(dp[n] != -1)
            return dp[n];

        dp[n] = ClimbStairsTopDown(n-1) + ClimbStairsTopDown(n-2);

        return dp[n];
    }

    public static int ClimbStairsBottomUp(int n)
    {
        if(n<=2)
            return n-1;
        
        CreateDp(n);

        dp[1] = 0;
        dp[2] = 1;

        for(int i=3;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
    public static void Main(string[] args)
    {
        
        int.TryParse(Console.ReadLine(),out int n);
        CreateDp(n);

        Console.WriteLine($"ClimbStaris:{ClimbStairsTopDown(n)}");
        Console.WriteLine($"ClimbStaris:{ClimbStairsBottomUp(n)}");

        return;
    }

}