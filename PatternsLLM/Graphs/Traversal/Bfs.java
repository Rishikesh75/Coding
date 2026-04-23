
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Bfs {
    

    public static class Graph
    {
        public List<List<Integer>> graph;
        public Graph(int n)
        {
            graph = IntStream.range(0,n)
                            .mapToObj(i -> new ArrayList<Integer>())
                            .collect(Collectors.toList());

            graph.get(0).add(1);
            graph.get(0).add(2);
        }


        public void display()
        {
            for(int i=0;i<graph.size();i++)
            {
                System.out.printf("%d:\t",i);
                for(var node : graph.get(i))
                {
                    System.out.printf("%d\t",node);
                }
                System.out.println();
            }

            return;
        }

        public void bfsTraversal()
        {
            List<Boolean> visitedArr = IntStream.range(0,graph.size())
                                        .mapToObj(i -> false)
                                        .collect(Collectors.toList());
            
            Queue<Integer> queue = new LinkedList<Integer>();
            queue.add(0);
            visitedArr.set(0,true);
            System.out.print("Bfs Traversal:");
            while(!queue.isEmpty())
            {

                int u = queue.peek();
                queue.poll();
                System.out.printf("%d\t",u);
                for(var v : graph.get(u)){
                    if(!visitedArr.get(v)){
                        visitedArr.set(v,true);
                        queue.add(v);
                    }
                }
            }

            System.out.println();
        }
    }

    public static void main(String[] args) {
        
        Graph graph = new Graph(3);

        graph.display();
        graph.bfsTraversal();
    }

}
