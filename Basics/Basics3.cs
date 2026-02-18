using System;
public class Helllooo
{
    public static bool IsEven(int num)
    {
        return num % 2 == 0 ?  true :   false;;
    }
    
    public static int LargestofNumber(int num1,int num2)
    {
        return num1>num2 ? num1 :num2;
    }

    public static int FindLargestNumber(int num1,int num2,int num3)
    {
        return num1>num2 ? (num1 > num3 ? num1 : num3) : (num2>num3 ? num2 : num3);
    }

    public static string checkNumber(int num1)
    {
        return num1 == 0 ? "Zero" : num1 > 0 ? "Positive" : "Negative";
    }
    
    public static bool checkLeepYear(int year)
    {
        return year % 4 == 0 ? (year % 100 == 0 ? (year % 400 == 0? true : false) :true) : false;
    }
    public static void Main(string[] args)
    {
        int.TryParse(Console.ReadLine(),out int num1);
        int.TryParse(Console.ReadLine(),out int num2);
        int.TryParse(Console.ReadLine(),out int num3);
        Console.WriteLine($"IsEven{IsEven(num1)}");

        Console.WriteLine($"LargestNumber{LargestofNumber(num1,num2)}");

        Console.WriteLine($"FindLargestNumber{FindLargestNumber(num1,num2,num3)}");

        Console.WriteLine($"checkNumber{checkNumber(num1)}");

        Console.WriteLine($"checkLeepYear{checkLeepYear(2004)}");
    }
}