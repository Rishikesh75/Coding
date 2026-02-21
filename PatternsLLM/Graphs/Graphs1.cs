
using System;
using System.Collections.Generic;
public class Program
{
    
    public static List<List<int>> CreateArr(int n)
    {
        List<List<int>>graph = new List<List<int>>();

        for(int i=0;i<n;i++)
        {
            graph.Add(new List<int>(){});
        }

        graph[0].AddRange(new List<int>(){1,2});

        return graph;
    }
    
    public static void DisplayGraph(List<List<int>> graph)
    {
        foreach(var arr in graph)
        {
            foreach(var item in arr)
            {
                Console.Write($"{item}\t");
            }
            Console.WriteLine();
        }
    }

    public static void Dfs(List<List<int>> graph)
    {
        List<bool> visitedArr = new List<bool>(graph.Count);
        for(int i = 0; i < graph.Count; i++)
        {
            visitedArr.Add(false);
        }
        
        Stack<int> stack = new Stack<int>();
        stack.Push(0);
        visitedArr[0] = true;
        
        while(stack.Count!=0)
        {
            int val = stack.Peek();
            Console.Write($"{val}\t");
            stack.Pop();
            foreach(var node in graph[val])
            {
                if(!visitedArr[node])
                {
                    stack.Push(node);
                    visitedArr[node] = true;
                }
            }
        }
        
        Console.WriteLine();
    }

    public static List<bool> visitedArr;
    public static void DfsRecurssion(List<List<int>>graph,int startNode)
    {
        Console.Write($"{startNode}\t");

        foreach(var node in graph[startNode])
        {
            if(!visitedArr[node])
                DfsRecurssion(graph,node);   
        }

    }

    public static void  Bfs(List<List<int>> graph)
    {
        List<bool>visitedArr = new List<bool>(graph.Count);
        
        for(int i=0;i<graph.Count;i++)
        {
            visitedArr.Add(false);
        }

        Queue<int>queue = new Queue<int>(){};
        queue.Enqueue(0);
        visitedArr[0] = true;

        while(queue.Count != 0)
        {
            int val = queue.Peek();
            Console.Write($"{val}\t");
            queue.Dequeue();
            foreach(var node in graph[val])
            {
                if(!visitedArr[node])
                {
                    queue.Enqueue(node);
                    visitedArr[node] = true;
                }
            }
        }

    }
    public static void Main(string[] args)
    {
        int n = 3;
        var graph = CreateArr(n);

        DisplayGraph(graph);


        Console.WriteLine("----Dfs Traversal----");
        Dfs(graph);


        Console.WriteLine("----Bfs Traversal----");
        Bfs(graph);

        Console.WriteLine();
        Console.WriteLine("----Dfs Traversal Recurssion----");
        visitedArr = Enumerable.Repeat(false,n).ToList();
        DfsRecurssion(graph,0);
    }
}