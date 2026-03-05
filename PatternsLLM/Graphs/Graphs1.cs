//Grapsh Done
using System;
using System.Collections.Generic;

public class Program
{
    public static List<List<int>> CreateGraph()
    {
        List<List<int>> graph =  new List<List<int>>{
            new List<int>{1,2},
            new List<int>{},
            new List<int>{}
            };

        return graph;
    }
    
    public static void Display(List<List<int>>graph)
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


    public static void Dfs(List<List<int>>graph)
    {
        List<bool> visitedarr = Enumerable.Repeat(false,graph.Count).ToList();
        Stack<int>stack = new Stack<int>();

        stack.Push(0);
        visitedarr[0] = true;
        Console.Write("Dfs:");

        while(stack.Count != 0)
        {
            
            int currNode = stack.Peek();
            stack.Pop();

            Console.Write($"{currNode}\t");

            foreach(var node in graph[currNode])
            {
                if(!visitedarr[node])
                {
                    visitedarr[node] = true;
                    stack.Push(node);
                }
            }
        }

        Console.WriteLine();
        return;
    }

    public static void DFSRecurssion(List<List<int>>graph,int currNode,List<bool>visitedArr)
    {
        visitedArr[currNode] = true;

        // Console.Write($"{currNode}");

        foreach(var node in graph[currNode])
        {
            if(!visitedArr[node])
                DFSRecurssion(graph,node,visitedArr);
        }

        return;
    }

    public static void BFS(List<List<int>>graph,int currNode)
    {
        List<bool>visitedArr = Enumerable.Repeat(false,graph.Count).ToList();

        Queue<int> queue = new Queue<int>();
        queue.Enqueue(0);
        visitedArr[0] = true;
        Console.Write("BFS:\t");
        while(queue.Count !=0)
        {
            
            int top = queue.Peek();
            queue.Dequeue();

            Console.Write($"{top}\t");

            foreach(var val in graph[top])
            {
                if(!visitedArr[val])
                {
                    queue.Enqueue(val);
                    visitedArr[val] = true;
                }
            }
        }
        Console.WriteLine();
    }

    public static void  Main(string[] args)
    {
        
        var graph = CreateGraph();

        Display(graph);

        Dfs(graph);

        Console.Write("Dfs Recurssion:");
        DFSRecurssion(graph,0,Enumerable.Repeat(false,graph.Count).ToList());
        Console.WriteLine();

        BFS(graph,0);


        int noOfConnectedComponent = 0;
        var visitedArr = Enumerable.Repeat(false,graph.Count).ToList();
        for(int i=0;i<graph.Count;i++)
        {
            if(!visitedArr[i])
            {
                DFSRecurssion(graph,i,visitedArr);
                noOfConnectedComponent++;
            }    
        }

        Console.WriteLine($"Connected Componenets:{noOfConnectedComponent}\t");
    }

}