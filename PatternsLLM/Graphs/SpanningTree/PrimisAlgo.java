
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class PrimisAlgo {
    

    public static class Graph{

        public static class Edges{
            public int u;
            public int v;
            public int wt;

            public Edges(int u,int v,int wt){
                this.u = u;
                this.v = v;
                this.wt = wt;
            }
        }

        public static class Node{
            public int v;
            public int wt;

            public  Node(int v,int wt){
                this.v = v;
                this.wt = wt;
            }
        }


        List<List<Node>> graph;


        public Graph()
        {
            graph = IntStream.range(0,3)
                    .mapToObj(i -> new ArrayList<Node>())
                    .collect(Collectors.toList());

            graph.get(0).addAll(List.of(new Node(1,1),new Node(2,2)));
        }

        public void display(){
            for(int i=0;i<graph.size();i++){
                System.out.printf("%d -->",i);
                for(var v: graph.get(i)){
                    System.out.printf("%d %d\t",v.v,v.wt);
                }
                System.out.println();
            }
        }


        public List<Edges> edges = new ArrayList<>();

        public void displayEdges()
        {
            System.out.println("Edges:");
            for(var edge : edges){
                System.out.printf("%d %d %d \n",edge.u,edge.v,edge.wt);
            }

            return;
        }

        public void MSTPrimsAlgo(int startNode)
        {
            List<Boolean> visitedArr = IntStream.range(0,graph.size())
                                                .mapToObj(i -> false)
                                                .collect(Collectors.toList());
            
            PriorityQueue<Edges> pq = new PriorityQueue<Edges>((Edges e1,Edges e2) -> e1.wt - e2.wt);

            pq.add(new Edges(startNode, -1, -1));
            visitedArr.set(startNode,true);

            while(!pq.isEmpty()){

                var u = pq.peek().u;
                var wt = pq.peek().wt;
                var v1 = pq.peek().v;
                pq.poll();

                if(v1 != -1){
                    edges.add(new Edges(u, v1, wt));
                }

                if(v1 != -1 && visitedArr.get(v1)){
                    continue;
                }

                for(var v : graph.get(u)){

                    if(!visitedArr.get(v.v)){
                        pq.add(new Edges(u,v.v,v.wt));
                        visitedArr.set(v.v,true);
                    }
                }

            }


            displayEdges();

        }

    }


    public static void main(String[] args){

        Graph graph = new Graph();

        graph.display();

        graph.MSTPrimsAlgo(0);
        return;
    }
}
