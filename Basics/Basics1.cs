using System;
public class Basic
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Helllooo c#..");

        Console.WriteLine("Enter the Name..");
        string name = Console.ReadLine();

        Console.WriteLine("Enter the Age..");
        int.TryParse(Console.ReadLine(),out int age);

        Console.WriteLine("Enter the City..");
        string city = Console.ReadLine();

        Console.WriteLine("{0} {1} {2}",name,age,city);

        Console.WriteLine("Enter the n:");
        int.TryParse(Console.ReadLine(),out int n);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                Console.Write("*");
            }
            Console.WriteLine();
        }

    }
}