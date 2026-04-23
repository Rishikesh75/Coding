
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Tp2 {
    

    public static class Graph{

        List<List<Integer>> graph;

        public Graph()
        {
            graph = IntStream.range(0,3)
                                .mapToObj(i-> new ArrayList<Integer>())
                                .collect(Collectors.toList());

            graph.get(0).addAll(List.of(1,2));

            indegree = IntStream.range(0,3)
                        .mapToObj(i -> 0)
                        .collect(Collectors.toList());
        }

        public void display()
        {
            int node  = 0;

            for(var u : graph){
                System.out.printf("%d -->",node);
                
                for(var v : graph.get(node)){
                    System.out.printf("%d\t",v);
                }
                
                System.out.println();
                node++;
            }

        }

        public List<Integer> indegree;

        public void createInDegree()
        {
            for(int i=0;i<graph.size();i++){
                for(var v : graph.get(i)){
                    indegree.set(v,indegree.get(v)+1);
                }
            }

            System.out.printf("Indegree Value:");
            for(int i=0;i<indegree.size();i++){
                System.out.printf("%d",indegree.get(i));
            }
            System.out.println();

        }

        public void topologicalSort2()
        {
            createInDegree();

            Queue<Integer> queue = new LinkedList<Integer>();

            for(int i=0;i<indegree.size();i++){
                if(indegree.get(i) == 0){
                    queue.add(i);
                }
            }

            System.out.printf("Topological Sort:");

            while(!queue.isEmpty()){

                int u = queue.peek();
                queue.poll();
                System.out.printf("%d\t",u);
                for(var v : graph.get(u)){
                    indegree.set(v,indegree.get(v) - 1);

                    if(indegree.get(v) == 0){
                        queue.add(v);
                    }
                }
            }

            System.out.println();
        }

    }

    public static void main(String[] args) {
        

        Graph graph = new Graph();
        graph.display();
        
        graph.topologicalSort2();
        return;
    }
}
