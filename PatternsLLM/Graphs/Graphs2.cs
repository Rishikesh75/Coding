//Topological Sort
using System;
using System.Collections.Generic;
public class Program
{
    
    public static List<List<int>> CreateGraph(int n)
    {
        List<List<int>> graph = new List<List<int>>();

        for(int i = 0; i < n; i++)
        {
            graph.Add(new List<int>());
        }

        graph[0].AddRange(new List<int>() { 1, 2 });

        return graph;
    }
    
    public static void DisplayGraph(List<List<int>> graph)
    {
        foreach(var edges in graph)
        {
            foreach(var node in edges)
            {
                Console.Write($"{node}\t");
            }
            Console.WriteLine();
        }
    }

    public static Stack<int> stack;
    public static void dfs(List<List<int>>graph,int currentNode,List<bool>visitedArr)
    {
        
        foreach(var node in  graph[currentNode])
        {
            if(!visitedArr[node])
            {
                visitedArr[node] = true;
                dfs(graph,node,visitedArr);
            }
        }
        
        stack.Push(currentNode);
        return;
    }
    public static void DisplayTopologicalSort()
    {
        Console.WriteLine("Topological Sort Order");
        while(stack.Count!=0)
        {
            Console.WriteLine($"{stack.Peek()}");
            stack.Pop();
        }
        return;
    }
    public static void TopologicalSort1(List<List<int>> graph)
    {
        List<bool> visitedArr = Enumerable.Repeat(false,graph.Count).ToList();
        stack = new Stack<int>();
        for(int i=0;i<graph.Count;i++)
        {
            if(!visitedArr[i])
            {
                visitedArr[i] = true;
                dfs(graph,i,visitedArr);
            }
        }

        DisplayTopologicalSort();
    }
    public static void Main(string[] args)
    {
        List<List<int>> graph = CreateGraph(3);

        DisplayGraph(graph);
        
        TopologicalSort1(graph);

        return;
    }
}