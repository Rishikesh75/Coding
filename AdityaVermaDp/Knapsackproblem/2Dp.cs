using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    
    public static List<int> Arr;
    public static int Sum;
    public static List<List<int>> dp;
    public static void CreateArr()
    {
        Arr = new List<int>(){2,3,7,8,10};
        Sum = 11;
    }
    
    public static bool SubSetSum(int sum,int currIndx)
    {
        
        if(sum == 0)
            return true;
        
        if(currIndx < 0)
            return false;
        
        return SubSetSum(sum-Arr[currIndx],currIndx-1) || SubSetSum(sum,currIndx-1);
    }
    
    public static bool SubSetSumTD(int sum,int currIndx)
    {
        if(sum == 0)
            return true;
        
        if(currIndx < 0 || sum < 0)
            return false;
        
        if(dp[currIndx][sum]!=-1)
        {
           return dp[currIndx][sum] == 1 ?  true :  false;
        }
            
        var val =  SubSetSumTD(sum-Arr[currIndx],currIndx-1) || SubSetSumTD(sum,currIndx-1);
        
        dp[currIndx][sum] = val ? 1 : 0;
        
        return val;
    }
    
    public static bool SubSetSumBottomUp()
    {
        List<List<bool>> dp1 = Enumerable.Range(0,Arr.Count)
                        .Select(_ => Enumerable.Repeat(false,Sum+1).ToList())
                        .ToList();
                        
        
        
        for(int i=0;i<Arr.Count;i++)
            dp[i][0] = true;
        
        if(Arr[0] <= Sum)
            dp[0][Arr[0]] = true;
        
        
        for(int i=1;i<Arr.Count;i++)
        {
            for(int s = 0;s<=Sum;s++)
            {
                var notTake = dp[i-1][s];
                
                var take = false;
                
                if(s >= Arr[i])
                    take = dp1[i-1][s-Arr[i]];
                
                dp[i][s] = Take || notTake;
            }
        }
        
        return dp[Arr.Count-1][Sum];
            
    }
    public static void CreateDp()
    {
        dp = Enumerable.Range(0,Arr.Count)
                        .Select(_ => Enumerable.Repeat(-1,Sum+1).ToList())
                        .ToList();
                        
        return;
                        
    }
    public static void Main(string[] args)
    {
        CreateArr();
        
        Console.WriteLine($"SubSetSum:{SubSetSum(Sum,Arr.Count-1)}");
        
        CreateDp();
        Console.WriteLine($"SubSetSum:{SubSetSumTD(Sum,Arr.Count-1)}");
        
        Console.WriteLine($"SubSetSum:{SubSetSumBottomUp()}");
        return;
    }
}