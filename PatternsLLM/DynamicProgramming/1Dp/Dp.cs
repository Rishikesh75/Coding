using System;
using System.Collections.Generic;

public class Program
{
    
    public static void CreateDp(int n)
    {
        dp  = Enumerable.Repeat(-1,n+1).ToList();
    }

    public static List<int> dp;
    public static int Fib(int n)
    {
        if(n<=2)
            return n-1;

        return Fib(n-1) + Fib(n-2);
    }

    public static int FibTopDown(int n)
    {
        if(n <=2)
            return n-1;

        if(dp[n] != -1)
            return dp[n];

        dp[n] = FibTopDown(n-1) + FibTopDown(n-2); 

        return dp[n];
    }
    
    
    public static int FibBottomUp(int n)
    {
        CreateDp(n);

        if(n <= 2)
            return n-1;
        
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

        Console.WriteLine($"Fib Value:{FibTopDown(n)}");

        Console.WriteLine($"Fib Value:{FibBottomUp(n)}");
    }
}