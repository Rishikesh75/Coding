using System;

public class Test
{
	
	public static int Recurssion(int currIndx,int weight)
	{
	   if(currIndx == n)
	        return 0;
	        
	   var take = 0;
	   
	   if(weight + wt[currIndx] <= WCap)
	        Recurssion(currIndx+1,weight + wt[currIndx]);
	   
	   var ntake = Recurssion(currIndx+1,weight);
	   
	   return Math.Max(take,ntake);
	}
	
	public static int RecurssionTopDown(int currIndx,int weight)
	{
	    if(currIndx == n)
	        return 0;
	   
	    if(dp[currIndx][weight] != -1)
	        return dp[currIndx][weight];
	       
	   var take = 0;
	   
	   if(weight+wt[currIndx] <= WCap)
	        RecurssionTopDown(currIndx,weight+wt[currIndx]);
	    
	   var ntake = RecurssionTopDown(currIndx+1,weight);
	   
	   dp[currIndx][weight] = Math.Max(take,ntake);
	    
	   return dp[currIndx][weight];
	}
	
	public static int RecurssionBottomUp()
	{
	    for(int i=n-1;i>=0;i--)
	    {
	        for(int w=WCap;w>=0;w--)
	        {
	            var take = 0;
	            if(w + wt[i] <= WCap)
	                take = dp[i][w+wt[i]];
	            
	            var ntake = dp[i+1][w];
	            
	            dp[i][w] = Math.Max(take,ntake);
	        }
	    }
	    
	    return dp[0][0];
	}
	public static void Main()
	{
	    
	}
}
