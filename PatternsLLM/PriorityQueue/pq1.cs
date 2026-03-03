using System;
using System.Collections.Generic;
using System.Linq;
public class Hello
{
    public class CustomComparitor : IComparer<int>
    {
        public int Compare(int a,int b)
        {
            return a.CompareTo(b);
        }
    }
    public static void Main(string[] args)
    {
        // // List<int> list = Enumerable.Repeat(0,4).ToList();
        // // List<int> list = Enumerable.Range(0,3).Select(x => x + 1).ToList();
        
        // List<List<int>> list = Enumerable.Range(0,5).Select(_ => Enumerable.Repeat(0,5).ToList()).ToList();
        
        // foreach(var val in list)
        // {
        //     foreach(var item in val)
        //     {
        //         Console.Write($"{item}\t");
        //     }
        //     Console.WriteLine();
        // }
        // // list.Add(1);
        // // list.AddRange(new List<int>(){1,2,3});
        
        // // list.Insert(1,1);
        // // list.InsertRange(1,new List<int>(){1,2,3});
        
        
        // // list.Remove(1);
        // // list.RemoveAt(1);
        // // list.RemoveRange(1,2);
        // // list.RemoveAll(x => x ==1);
        
        // // list.Contains(1);
        // // list.Find(x=>x==1);
        // // list.FindAll(x => x==1);
        
        // // list.Sort();
        // // list.Reverse();
        // // foreach(var val in list)
        // // {
        // //     Console.Write($"{val}\t");
        // // }
        
        
        // Dictionary<int,int>dict = new Dictionary<int,int>();
        
        // dict.Add(1,1);
        
        // dict.ContainsKey(1);
        
        // Console.WriteLine();
        // foreach(var val in dict)
        // {
        //     Console.WriteLine($"{val.Key} {val.Value}");
        // }
        
        // HashSet<int> set = new HashSet<int>(){1,2,3};
        // HashSet<int> set2 = new HashSet<int>(){2,3,4};
        
        // set.Add(1);
        // set.Contains(1);
        // set.Remove(1);
        
        // set.UnionWith(set2);
        // set.IntersectWith(set2);
        // set.ExceptWith(set2);
        // set.SymmetricExceptWith(set2);
        
        // Stack<int> stack = new Stack<int>();
        // stack.Push(1);
        // while(stack.Count !=0)
        // {
        //     Console.WriteLine($"{stack.Peek()}");
        //     stack.Pop();
        // }
        
        // Queue<int> queue = new Queue<int>();
        
        // queue.Enqueue(2);
        // while(queue.Count != 0)
        // {
        //     Console.WriteLine($"{queue.Peek()}");
        //     queue.Dequeue();
        // }
        
        PriorityQueue<int,int> pq = new PriorityQueue<int,int>(new CustomComparitor());
        
    }
}