using System;
using System.Collections.Generic;

public class Program
{
    public static List<List<int>> CreateGraph()
    {
        List<List<int>> graph = new List<List<int>>()
        {
            new List<int>(){1,2},
            new List<int>(){},
            new List<int>(){3},
            new List<int>(){}
        };

        return graph;
    }

    public static void Display(List<List<int>> graph)
    {
        foreach(var Edges in graph)
        {
            foreach(var node in Edges)
            {
                Console.Write($"{node}\t");
            }
                Console.WriteLine();
        }
    }

    public static void dfs(List<List<int>>graph,int currNode,List<bool> visitedarr)
    {
        visitedarr[currNode] = true;

        foreach(var node in graph[currNode])
        {
            if(!visitedarr[node])
                dfs(graph,node,visitedarr);
        }

        stack.Push(currNode);

        return;
    }

    public static Stack<int> stack = new Stack<int>();
    public static void TopologicalSort(List<List<int>> graph)
    {
    
        List<bool>visitedarr = Enumerable.Repeat(false,graph.Count).ToList();

        for(int i=0;i<graph.Count;i++)
        {
            if(!visitedarr[i])
                dfs(graph,i,visitedarr);
        }    

        Console.Write("Topological Sort:");
        while(stack.Count !=0)
        {
            int val = stack.Peek();
            stack.Pop();

            Console.Write($"{val}\t");
        }
        Console.WriteLine();
    }


    public static void TopologicalSort2(List<List<int>> graph)
    {

        List<int> inDegree = Enumerable.Repeat(0,graph.Count).ToList();

        foreach(var edge in graph)
        {
            foreach(var node in edge)
            {
                inDegree[node]++;
            }
        }

        Queue<int> queue = new Queue<int>();

        foreach(var node in inDegree)
        {
            if(inDegree[node] == 0)
                queue.Enqueue(node);
        }

        Console.Write("Topological Sort:\t");
        while(queue.Count !=0)
        {
            
            int u = queue.Peek();
            queue.Dequeue();

            Console.Write($"{u}\t");

            foreach(var v in graph[u])
            {
                inDegree[v]--;
                if(inDegree[v] == 0)
                    queue.Enqueue(v);
            }

        }
        Console.WriteLine();
        return;

    }
    public static void Main()
    {
        var graph = CreateGraph();

        Display(graph);

        TopologicalSort(graph);

        TopologicalSort2(graph);
    }

}