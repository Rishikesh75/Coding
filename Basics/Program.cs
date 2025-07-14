using System;

namespace Basics
{
    public class Program
    {
        public static void Program1()
        {
            Console.Write("Enter the UserName: ");
            string name = Console.ReadLine();

            Console.Write($"Enter the age of {name}: ");
            if (!int.TryParse(Console.ReadLine(), out int age))
            {
                Console.WriteLine("Invalid age entered.");
                return;
            }

            Console.WriteLine($"Hi {name}, your age is {age}");
        }

        public static void Program2()
        {
            Console.Write("Enter a number: ");
            if (!int.TryParse(Console.ReadLine(), out int number))
            {
                Console.WriteLine("Invalid number.");
                return;
            }

            if (number % 2 == 0)
                Console.WriteLine("Even Number");
            else
                Console.WriteLine("Odd Number");
        }

        public static void Program3()
        {
            Console.Write("Enter Number 1: ");
            if (!int.TryParse(Console.ReadLine(), out int num1))
            {
                Console.WriteLine("Invalid input.");
                return;
            }

            Console.Write("Enter Number 2: ");
            if (!int.TryParse(Console.ReadLine(), out int num2))
            {
                Console.WriteLine("Invalid input.");
                return;
            }

            Console.Write("Enter Operator (+, -, *, /): ");
            char op = Console.ReadKey().KeyChar;
            Console.WriteLine();

            switch (op)
            {
                case '+':
                    Console.WriteLine($"Result: {num1 + num2}");
                    break;
                case '-':
                    Console.WriteLine($"Result: {num1 - num2}");
                    break;
                case '*':
                    Console.WriteLine($"Result: {num1 * num2}");
                    break;
                case '/':
                    if (num2 == 0)
                        Console.WriteLine("Error: Division by zero");
                    else
                        Console.WriteLine($"Result: {num1 / num2}");
                    break;
                default:
                    Console.WriteLine("Invalid operator entered.");
                    break;
            }
        }

        public static void Program4()
        {
            Console.Write("Enter the nth number in Fibonacci series: ");
            if (!int.TryParse(Console.ReadLine(), out int n) || n <= 0)
            {
                Console.WriteLine("Please enter a positive integer.");
                return;
            }

            if (n == 1)
            {
                Console.WriteLine("Number is: 0");
            }
            else if (n == 2)
            {
                Console.WriteLine("Number is: 1");
            }
            else
            {
                int a = 0, b = 1;
                for (int i = 3; i <= n; i++)
                {
                    int temp = a + b;
                    a = b;
                    b = temp;
                }
                Console.WriteLine($"Number is: {b}");
            }
        }

        public static void PrimeNumberCheck()
        {
            Console.Write("Enter a number: ");
            if (!int.TryParse(Console.ReadLine(), out int num))
            {
                Console.WriteLine("Invalid input.");
                return;
            }

            if (num <= 1)
            {
                Console.WriteLine("Not prime or composite.");
                return;
            }

            bool isPrime = true;
            for (int i = 2; i <= Math.Sqrt(num); i++)
            {
                if (num % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }

            Console.WriteLine(isPrime ? "Prime Number" : "Composite Number");
        }
        public static void ReverseString()
        {
            Console.WriteLine("Enter the String");
            string str = Console.ReadLine();
            string Revstr = "";
            for(int i=str.Length-1;i>=0;i--)
            {
                Revstr = Revstr + str[i];
            }
            Console.WriteLine($"Reversed String:{Revstr}");
        }

        public static void FindLargestElementArr()
        {
            Console.WriteLine("Enter the Size of the array:");
            int.TryParse(Console.ReadLine(),out int n);
            int[] arr = new int[n];
            for(int i=0;i<n;i++)
            {
                int.TryParse(Console.ReadLine(),out arr[i]);
            }
            int Largest  = arr[0];
            for(int i=1;i<n;i++)
            {
                if(arr[i]>Largest)
                {
                    Largest = arr[i];
                }
            }
            Console.WriteLine($"LargestElement:{Largest}");
        }
        public static void Main(string[] args)
        {
            // // Uncomment the method you want to run
            // // Program1();
            // // Program2();
            // // Program3();
            // // Program4();
            // //PrimeNumberCheck();
            // //ReverseString();
            // FindLargestElementArr();
            Student student = new Student(1,"Rishi");
            Console.WriteLine($"{student.id}:{student.Name}");
        }
    }

    public class Student
    {
        public int id;
        public string Name;
        public Student(int id,string Name)
        {
            this.id = id;
            this.Name = Name;
        }
    }
}
