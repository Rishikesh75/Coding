using System;
public class Basic5
{
    
    public static void PrintN(int n)
    {
        for(int i=1;i<=n;i++)
        {
            Console.Write($"{i}\t");
        }
        Console.WriteLine();
    }

    public static int FindSum(int n)
    {
        int sum = 0;
        for(int i=0;i<=n;i++)
        {
            sum = sum + i;
        }
        return sum;
    }

    public static void mutipleN(int n)
    {
        for(int i=1;i<=10;i++)
        {
            Console.WriteLine($"{n} * {i} : {n*i}");
        }
    }

    public static int FindFactorial(int n)
    {
        int val = 1;
        for(int i=1;i<=n;i++)
        {
            val = val * i;
        }
        return val;
    }

    public static int ReverseNumber(int n)
    {
        int reversedNum = 0;
        while(n != 0)
        {
            int rem = n % 10;
            reversedNum = reversedNum * 10 + rem;
            n = n/10;
        }
        return reversedNum;
    }

    public static void PrintFib(int n)
    {
        int num1 = 0;
        int num2 = 1;
        if(n >= 1) Console.Write($"{num1}");
        if(n>=2) Console.Write($"{num2}");
        
        for(int i = 3;i<=n;i++)
        {
            int temp = num1 + num2;
            num1 = num2;
            num2 = temp;
            Console.Write($"{num2}");
        } 
        Console.WriteLine();
    
    }

    public static bool isPrime(int n)
    {
        for(int i=2;i<n;i++)
        {
            if(n % i == 0) return false;
        }
        return true;
    }
    public static void Main(string[] args)
    {
        int.TryParse(Console.ReadLine(),out int n);   
        PrintN(n); 
        Console.WriteLine($"sum:{FindSum(n)} factorial:{FindFactorial(n)} reversedNum:{ReverseNumber(n)} isPrime:{isPrime(n)}");
        mutipleN(n);
        PrintFib(n);
    }
}