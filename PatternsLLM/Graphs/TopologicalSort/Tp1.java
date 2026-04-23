
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Tp1
{
    public static class Graph{
        List<List<Integer>> graph;

        public Graph() {
            graph = IntStream.range(0, 3)
                             .mapToObj(i -> new ArrayList<Integer>())
                             .collect(Collectors.toList());

            graph.get(0).addAll(List.of(1,2));
        }

        public void display()
        {
            int u = 0;
            for(var edge : graph){
                System.out.printf("%d-->\t",u);
                for(var v : edge){
                    System.out.printf("%d\t",v);
                }
                System.out.println();
                u++;
            }
        }
        public List<Boolean> visitedarr = new ArrayList<Boolean>(Collections.nCopies(3,false));

        public Stack<Integer> stack = new Stack<>();
        public void displayStack()
        {
            while(!stack.isEmpty()){
                System.out.printf("%d",stack.peek());
                stack.pop();
            }
        }

        public void TopologicalSort1(int currNode){
            visitedarr.set(currNode,true);

            for(var v : graph.get(currNode)){

                if(!visitedarr.get(v)){
                    TopologicalSort1(v);
                }
            }

            stack.push(currNode);
        }


    }
    
    public static void main(String[] args) {
        
        Graph graph = new Graph();

        graph.display();

        graph.TopologicalSort1(0);
        graph.displayStack();
        return;
    }
}