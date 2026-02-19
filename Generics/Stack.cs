using System;
using System.Collections.Generic;
public class Program
{
    public static void Main(string[] args)
    {
        Stack<int> stack = new();

        stack.Push(1);
        stack.Push(2);

        while(stack.Count != 0)
        {
            int top = stack.Peek();
            Console.Write($"{top}\t");
            stack.Pop();
        }
    }
}