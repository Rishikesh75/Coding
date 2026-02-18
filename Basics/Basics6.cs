using System;
public class Basics6
{
    public static void pattern1(int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                Console.Write("*");
            }
            Console.WriteLine();
        }
    }
    
    public static void pattern2(int n)
    {
        int startval = n;
        int endval = n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2*n-1;j++)
            {
                if(j>=startval && j<=endval)Console.Write("*");
                else Console.Write(" ");
            }
            Console.WriteLine();
            startval--;
            endval++;
        }
    }

    public static void pattern3(int n)
    {
        int startval = n;
        int endval = n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2*n-1;j++)
            {
                if(j>=startval && j<=endval)Console.Write("*");
                else Console.Write(" ");
            }
            Console.WriteLine();
            startval--;
            endval++;
        }
        startval += 2;
        endval  -= 2;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=2*n-1;j++)
            {
                if(j>=startval && j<=endval) Console.Write("*");
                else Console.Write(" ");
            }
            Console.WriteLine();
            startval++;
            endval--;
        }
    }
    public static void Main(string[] args)
    {
        
        int.TryParse(Console.ReadLine(),out int n);
        pattern1(n);
        pattern2(n);
        pattern3(n);
    }
}