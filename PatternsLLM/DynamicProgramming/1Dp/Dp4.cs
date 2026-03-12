using System;
using System.Collections.Generic;

public class Program
{
    
    public static int Dw(string s,int n)
    {
        if(n == 0)
            return 1;
        
        int val = (s[n-1] - '0') * 10 + (s[n] - '0');
        
        if(val >26)
            return Dw(s,n-1);
        else 
            return 1 + Dw(s,n-1);   
    }

    public static void Main(string[] args)
    {
        string s = Console.ReadLine();

        Console.WriteLine($"DecodedWays:{Dw(s,s.Length-1)}");

        
        return;
    }
}