using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    
    public static List<int> Wt;
    public static List<int> V;
    public static int Wcap;
    public static int n;
    public static List<List<int>> dp;
    
    public static void CreateDp()
    {
        
        dp = Enumerable.Range(0,n)
                        .Select(_ => Enumerable.Repeat(-1,Wcap+1).ToList())
                        .ToList();
        return;
    }
    
    public static List<List<int>> CreateDpBottomUp()
    {
         dp = Enumerable.Range(0,n+1)
                        .Select(_ => Enumerable.Repeat(0,Wcap+1).ToList())
                        .ToList();
        return dp;
    }
    
    public static void Init()
    {
        Wt = new List<int>(){1,2,3};
        V = new List<int>(){1,2,3};
        Wcap = 5;
        n = Wt.Count;
    }
    
    public static int Kp(int currWt,int currIdx)
    {
        // Console.WriteLine($"{currWt} {currIdx}");
        
        if(currIdx >= n)
            return 0;
            
        int v1  = 0;
        
        if(currWt+Wt[currIdx] <= Wcap)
            v1 = V[currIdx] + Kp(currWt+Wt[currIdx],currIdx+1);
        
        int v2 = Kp(currWt,currIdx+1);
        
        return Math.Max(v1,v2);
    }
    
    public static int KpTopDown(int currWt,int currIdx)
    {
        if(currIdx >= n)
            return 0;
        
        if(dp[currIdx][currWt]!=-1)
            return dp[currIdx][currWt];
        
        int v1 = 0;
        
        if(currWt+Wt[currIdx] <= Wcap)
             v1 = V[currIdx] + Kp(currWt+Wt[currIdx],currIdx+1);
        
        int v2 = Kp(currWt,currIdx+1);
        
        dp[currWt][currIdx] = Math.Max(v1,v2);
        
        return dp[currWt][currIdx];
    }
    
    public static int KpTopDownRecurssion1(int currWt,int currIdx)
    {
        // Console.WriteLine($"{currWt} {currIdx}");
        
        if(currIdx >= n)
            return 0;
        
        if(currWt+Wt[currIdx]> Wcap)
            return 0;
        
        if(dp[currIdx][currWt]!=-1)
            return dp[currIdx][currWt];
            
        var v1 = V[currIdx] + KpTopDownRecurssion1(currWt+Wt[currIdx],currIdx+1);
        
        var v2 = KpTopDownRecurssion1(currWt,currIdx+1);
        
        dp[currIdx][currWt] = Math.Max(v1,v2);
        
        return dp[currIdx][currWt];
    
    }
    
    public static int KpBottomUp()
    {
        dp = CreateDpBottomUp();
        
        for(int i = n-1;i>=0;i++)
        {
            
            for(int w = 0;w<=Wcap;w++)
            {
                int take = 0;

                if(w + Wt[i] <= Wcap)
                    take = V[i] + dp[i + 1][w + Wt[i]];
                
                int skp = dp[i + 1][w];
                
                dp[i][w] = Math.Max(skp, take);
            }
        }
        
        return dp[0][0];
        
    }
    
    public static int KpRecurrsion1(int currWt,int currIdx)
    {
        if(currIdx >=n)
            return 0;
        
        if(currWt+Wt[currIdx] > Wcap)
            return -V[currIdx-1];
        
        var v1 = V[currIdx] + KpRecurrsion1(currWt+Wt[currIdx],currIdx+1);
        
        var v2 = KpRecurrsion1(currWt,currIdx+1);
        
        return Math.Max(v1,v2);
    }
    
    
    public static void Main(string[] args)
    {
        
        Init();
        CreateDp();
        
        Console.WriteLine($"KnapsackRecurssion:{Kp(0,0)}"); 
        
        Console.WriteLine($"KnapsackRecurssion:{KpRecurrsion1(0,0)}");
        
        Console.WriteLine($"KpTopDown:{KpTopDown(0,0)}");
        
        CreateDp();
        Console.WriteLine($"KpTopDownRecurssion1:{KpTopDownRecurssion1(0,0)}");
        
        Console.WriteLine($"KpBottomUp:{KpBottomUp()}");
        
        return;
    }
}