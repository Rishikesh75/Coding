using System;
using System.Collections.Generic;
public class Program
{
    
    public static List<List<(int V,int Wt)>> CreateGraph()
    {
        List<List<(int V,int Wt)>> graph = new List<List<(int V, int Wt)>>()
        {
            new List<(int V, int Wt)>(){(1,1),(2,2)},
            new List<(int V, int Wt)>(){},
            new List<(int V, int Wt)>(){(3,3)},
            new List<(int V,int Wt)>(){}
        };

        return graph;
    }

    public static void DisplayGraph(List<List<(int V,int Wt)>> graph)
    {
        foreach(var edges in graph)
        {
            foreach(var node in edges)
            {
                 Console.Write($"{node.V} {node.Wt} \t");
            }
            Console.WriteLine();
        }
    }

    
    public static void DikstraAlgorithm(List<List<(int V,int Wt)>>graph)
    {
        PriorityQueue<(int v,int wt),int> pq = new PriorityQueue<(int v,int wt),int>();

        List<int> distanceArr = Enumerable.Repeat(int.MaxValue,graph.Count).ToList();

        pq.Enqueue((0,0),0);

        while(pq.Count !=0)
        {
            var top = pq.Peek();
            pq.Dequeue();

            var u = top.v;
            var dis = top.wt;

            if(distanceArr[u] > dis)
                distanceArr[u] = dis;

            foreach(var node in graph[u])
            {
                if(distanceArr[node.V] > dis + node.Wt)
                    pq.Enqueue((node.V,dis+node.Wt),dis+node.Wt);
            }

        }

        Console.Write("Distance:");
        foreach(var dist in distanceArr)
        {
            Console.Write($"{dist}\t");
        }

        Console.WriteLine();
    }
    
    public static void Main(string[] args)
    {
        var graph = CreateGraph();

        DisplayGraph(graph);

        DikstraAlgorithm(graph);
    }


}