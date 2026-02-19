using System;
using System.Collections.Generic;
public class Program
{
    public static void Main(string[] args)
    {
        Queue<int>queue = new();

        queue.Enqueue(10);
        queue.Enqueue(10);

        while(queue.Count!=0)
        {
            int val = queue.Peek();
            queue.Dequeue();
            Console.Write($"{val}\t");
        }
    }
}