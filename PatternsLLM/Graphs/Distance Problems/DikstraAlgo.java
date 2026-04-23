
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class DikstraAlgo {
    
    
     public static class Pair{
            public int node;
            public int distance;

            public Pair(int node,int distance) {
                this.node = node;
                this.distance = distance;
            }
            
        }

    public static class Node{
        public int v;
        public int wt;

        Node(int v,int wt){
            this.v = v;
            this.wt = wt;
        }
    }
    public static class Graph
    {
       
        
        List<List<Node>> graph;
        public Graph()
        {
            graph = IntStream.range(0, 3)
                                .mapToObj(i -> new ArrayList<Node>())
                                .collect(Collectors.toList());

            graph.get(0).addAll(List.of(new Node(1,1),new Node(2,2)));

            distanceArr = IntStream.range(0, 3)
                                    .mapToObj(i -> Integer.MAX_VALUE)
                                    .collect(Collectors.toList());
        }

        public void display()
        {
            for(int i=0;i<graph.size();i++){
                System.out.printf("%d -->",i);
                for(var v : graph.get(i)){
                    System.out.printf("%d %d\t",v.v,v.wt);
                }
                System.out.println();
            }
        }

        public List<Integer> distanceArr;
        

        public void dikstraAlgoritham(int startNode)
        {
            distanceArr.set(startNode,0);

            PriorityQueue<Pair> pq = new PriorityQueue<Pair>((Pair p1,Pair p2) -> p1.distance - p2.distance);
            pq.add(new Pair(0,0));

            while(!pq.isEmpty()){
                
                var u = pq.peek().node;
                var dis = pq.peek().distance;

                pq.poll();

                for(var v : graph.get(u)){
                    if(distanceArr.get(v.v) > dis + v.wt){
                        distanceArr.set(v.v,dis + v.wt);
                        pq.add(new Pair(v.v, dis + v.wt));
                    }
                }

            }

            //DisplayArr
            int node = 0;
            for(var val : distanceArr){
                System.out.printf("node:%d dis:%d",node,val);
                node++;
            }
            System.out.println();

        }
    }

    public static void main(String[] args){

        Graph graph = new Graph();

        graph.display();
        graph.dikstraAlgoritham(0);
        return;
    }
}
