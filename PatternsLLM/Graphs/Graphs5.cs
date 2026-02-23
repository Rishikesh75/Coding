using System;
using System.Collections.Generic;
public class Program
{
    public static List<List<(int Node,int Weight)>>CreateGraph()
    {
        return new List<List<(int Node,int Weight)>>()
        {
            new List<(int Node,int Weight)>(){(1,1),(2,2)},
            new List<(int Node,int Weight)>(){(0,1)},
            new List<(int Node,int Weight)>(){(0,2)}
        };

    }
    
    public static void DisplayGraph(List<List<(int Node,int Weight)>> graph)
    {
        foreach(var edges in graph)
        {
            foreach(var edge in edges)
            {
                Console.Write($"{edge.Node} {edge.Weight}\t");
            }
            Console.WriteLine();
        }
    }

    public static void PrimiseAlgoritham(List<List<(int Node,int Weight)>>graph)
    {
        int Vcount = graph.Count;

        List<int> keys = new List<int>(Vcount);
        List<int> parent = new List<int>(Vcount);
        List<bool> visited = new List<bool>(Vcount);

        for(int i=0;i<graph.Count;i++)
        {
            visited[i] =false;
            keys[i] = int.MaxValue;
            parent[i] = -1;
        }

        keys[0] = 0;

        PriorityQueue<(int Node,int Weight),int> pq = new PriorityQueue<(int Node,int Weight), int>();
        pq.Enqueue((0,0),0);

        while(pq.Count !=0)
        {
            var (u,weight) = pq.Peek();

            if(visited[u] == true)
                continue;
            
            visited[u] = true;

            foreach(var (v,edgeWeight) in graph[u])
            {
                if(visited[v] == false && edgeWeight<keys[v])
                {
                    keys[v] = edgeWeight;
                    parent[v] = u;
                    pq.Enqueue((v,keys[v]),keys[v]);
                }
            }
        }
        return ;
    }
    public static void Main(string[] args)
    {
        var graph = CreateGraph();

        DisplayGraph(graph);
    }
}