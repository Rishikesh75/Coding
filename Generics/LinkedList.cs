using System;
using System.Collections.Generic;
public class Program
{
    public static void Main(string[] args)
    {
        LinkedList<int> linkedlist = new LinkedList<int>();

        linkedlist.AddLast(10);
        linkedlist.AddFirst(20);

        linkedlist.RemoveFirst();
        linkedlist.RemoveLast();

        var node = linkedlist.First;

        while(node.Next != null)
        {
            Console.Write($"{node.Value}\t");
            node = node.Next;
        }

        linkedlist.Remove(10);

        linkedlist.Remove(linkedlist.First);

        
    }
}