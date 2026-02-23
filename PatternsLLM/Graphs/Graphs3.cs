//'
using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    public static List<List<(int Node,int Weight)>> CreateGraph()
    {
        List<List<(int Node,int Weight)>> graph = new List<List<(int Node, int Weight)>>()
        {
            new List<(int Node,int Weight)>(){(1,1),(2,2)},
            new List<(int Node,int Weight)>(),
            new List<(int Node,int Weight)>()
        };

        return graph;
    }

    public static void DisplayDistance(List<int> DistanceArr)
    {
        int i = 0;
        foreach (var dis in DistanceArr)
        {
            Console.Write($"{i}:{dis}\t");
            i++;
        }
        Console.WriteLine();
    }

    public static void DikstraAlgorithm(List<List<(int Node,int Weight)>> graph, int Node)
    {
        List<int> distanceArr = Enumerable.Repeat(int.MaxValue, graph.Count).ToList();
        distanceArr[Node] = 0;

        PriorityQueue<(int Node,int Weight), int> pq = new PriorityQueue<(int Node, int Weight), int>();
        pq.Enqueue((Node, 0), 0);

        while (pq.Count != 0)
        {
            var currentNode = pq.Dequeue();

            if (currentNode.Weight > distanceArr[currentNode.Node])
                continue;

            foreach (var node in graph[currentNode.Node])
            {
                int newDistance = currentNode.Weight + node.Weight;

                // ✅ Proper relaxation step
                if (newDistance < distanceArr[node.Node])
                {
                    distanceArr[node.Node] = newDistance;
                    pq.Enqueue((node.Node, newDistance), newDistance);
                }
            }
        }

        DisplayDistance(distanceArr);
    }

    public static void Main(string[] args)
    {
        List<List<(int Node,int Weight)>> graph = CreateGraph();
        DikstraAlgorithm(graph, 0);
    }
}