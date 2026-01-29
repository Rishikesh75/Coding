using System;
using System.Text;
public class Basics1
{
    public static void Main(string[] args)
    {
        // Print "Hello, World!" to the console
        Console.WriteLine("Hello, World!");

        Console.WriteLine("Enter a number to check if it's even or odd:");
        int.TryParse(Console.ReadLine(), out int number);
        Console.WriteLine("Parsed number: " + number);

        if(number % 2 == 0)
        {
            Console.WriteLine("The number is even.");
        }
        else
        {
            Console.WriteLine("The number is odd.");
        }

        Console.WriteLine("Enter three numbers to find the largest among them:");
        int.TryParse(Console.ReadLine(), out int n1);
        int.TryParse(Console.ReadLine(), out int n2);
        int.TryParse(Console.ReadLine(), out int n3);

        if(n1>n2)
        {
            if(n1>n3)
            {
                Console.WriteLine("The largest number is: " + n1);
            }
            else
            {
                Console.WriteLine("The largest number is: " + n3);
            }
        }
        else
        {
            if(n2>n3)
            {
                Console.WriteLine("The largest number is: " + n2);
            }
            else
            {
                Console.WriteLine("The largest number is: " + n3);
            }
        }

        Console.WriteLine("Enter a number to check if it's positive, negative or zero:");
        int.TryParse(Console.ReadLine(), out int num);
        if(num>0)
        {
            Console.WriteLine("The number is positive.");
        }
        else if(num<0)
        {
            Console.WriteLine("The number is negative.");
        }
        else
        {
            Console.WriteLine("The number is zero.");
        }

        Console.WriteLine("Enter the number:");
        int.TryParse(Console.ReadLine(), out int N);
        for(int i=1;i<=N;i++)
        {
            Console.Write($"{i}\t");
        }
        Console.WriteLine();
        
        Console.Write("Enter the number:");
        int.TryParse(Console.ReadLine(), out N);
        int val = 1;
        for(int i=2;i<=N;i++)
        {
            val = val * i;
        }
        Console.WriteLine($"factorial:{val}");

        Console.WriteLine("Enter a number to check if it's prime:");
        int.TryParse(Console.ReadLine(), out int primeCandidate);
        int count = 0;
        for(int i=2;i<primeCandidate;i++)
        {
            if(primeCandidate % i == 0)
                count++;
        }
        if(count == 0)
            Console.WriteLine("Prime Number..");
        else
            Console.WriteLine("Composite Number");

        Console.WriteLine("Enter the number to be reversed:");
        int.TryParse(Console.ReadLine(),out int n);
        int reversedValue = 0;
        while(n!=0)
        {
            int rem = n % 10;
            reversedValue = reversedValue * 10 + rem;
            n = n / 10;
        }
        Console.WriteLine($"value:{reversedValue}");


        Console.WriteLine("Enter the Number");
        string s = Console.ReadLine();
        StringBuilder sb = new StringBuilder(s);
        // sb.Reverse();
        if(s.Equals(sb.ToString()))
        {
            Console.WriteLine("Yes Plaimdrome..");
        }
        else 
        {
            Console.WriteLine("Not Plaimdrome..");
        }
    }
}