using System;
using System.Collections.Generic;
public class Comparitor : IComparer<int>
{
    public  int Compare(int a,int b)
    {
        return b.CompareTo(a);
    }
}
public class Program
{
    public static void Main(string[] args)
    {
        PriorityQueue<string,int> pq = new PriorityQueue<string,int>(new Comparitor());
        
        pq.Enqueue("Hi",1);
        pq.Enqueue("dfsafd",22);

        while(pq.Count != 0)
        {
            Console.Write($"{pq.Peek()}\t");
            pq.Dequeue();
        }

        //Enqueue , Dequeue , Count , Peek
        return;
    }
}