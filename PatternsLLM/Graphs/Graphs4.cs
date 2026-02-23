
using System;
using System.Collections.Generic;
public class Program
{
    public class Edges
    {
        public  int Start;
        public int End;

        public int Weight;

        public Edges(int start,int end,int weight)
        {
            this.Start = start;
            this.End = end;
            this.Weight = weight;
        }
    }
    
    public static List<List<(int Node,int Weight)>> createGraph()
    {
        var graph = new List<List<(int Node,int Weight)>>()
        {
            new List<(int Node,int Weight)>(){(1,1),(2,2)},
            new List<(int Node,int Weight)>(),
            new List<(int Node,int Weight)>()  
        };

        return graph;
    }

    public static void Display(List<List<(int Node,int Weight)>>graph)
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
    public static List<Edges> CreateEdges(List<List<(int Node,int Weight)>>graph)
    {
        List<Edges>edges = new();
        
        for(int i=0;i<graph.Count;i++)
        {
            foreach(var edge in graph[i])
            {
                edges.Add(new Edges(i,edge.Node,edge.Weight));
            }
        }

        return edges;
    }
    public static void DisplayDistanceArr(List<int>distnaceArr)
    {
        int i=0;
        foreach(var val in distnaceArr)
        {
            Console.WriteLine($"{i}: {val}");
            i++;
        }

    }


    public static void BellamFoldAlogrithan(List<List<(int Node,int Weight)>>graph,int Node)
    {
        List<int> distanceArr = Enumerable.Repeat(int.MaxValue, graph.Count).ToList();
        distanceArr[Node] = 0;
        
        List<Edges>edges = CreateEdges(graph);

        for(int i=0;i<graph.Count;i++)
        {
            foreach(var edge in edges)
            {
                if(distanceArr[edge.Start] != int.MaxValue && distanceArr[edge.Start]+edge.Weight < distanceArr[edge.End])
                {
                    distanceArr[edge.End] = distanceArr[edge.Start]+edge.Weight;
                }
            }
        }

        foreach(var edge in edges)
        {
            if(distanceArr[edge.Start] != int.MaxValue && distanceArr[edge.Start]+edge.Weight < distanceArr[edge.End])
            {
                Console.WriteLine("Graph Contains the Negative Cycle");
                return;
            }
        }

        DisplayDistanceArr(distanceArr);


    }
    
    public static void Main(string[] args)
    {
            var graph = createGraph();

            Display(graph);

            BellamFoldAlogrithan(graph,0);
    }

}