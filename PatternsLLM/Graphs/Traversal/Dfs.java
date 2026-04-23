
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Dfs {
    

    public static class Graph{

        public List<List<Integer>> graph;

        public Graph(int n)
        {
            graph = IntStream.range(0,n)
                            .mapToObj(i -> new ArrayList<Integer>())
                            .collect(Collectors.toList());


            graph.get(0).addAll(List.of(1,2));

            initVisitedArr();
        }

        public  void display()
        {
            for(int i=0;i<graph.size();i++)
            {
                System.out.printf("%d -->",i);
                for(int j=0;j<graph.get(i).size();j++)
                {
                    System.out.printf("%d\t",graph.get(i).get(j));
                }
                System.out.println();
            }
        }

        public List<Boolean> visitedArr;

        public void initVisitedArr()
        {
            visitedArr = IntStream.range(0, graph.size())
                                    .mapToObj(i -> false)
                                    .collect(Collectors.toList());

        }
        
        public void dfs(int currNode)
        {

            System.out.printf("%d\t",currNode);
            visitedArr.set(currNode,true);

            for(var v : graph.get(currNode))
            {
                if(!visitedArr.get(v)){
                    dfs(v);
                }
            }

            return;
        }

        public void dfsRecurssiveTraversal(int currNode)
        {
            initVisitedArr();

            Stack<Integer> stack = new Stack<Integer>();

            stack.push(currNode);
            visitedArr.set(currNode,true);

            System.out.printf("Dfs Traversal:");
            while(!stack.isEmpty()){

                int u = stack.peek();
                stack.pop();
                System.out.printf("%d\t",u);

                for(var v : graph.get(u)){

                    if(!visitedArr.get(v)){
                        stack.push(v);
                        visitedArr.set(v,true);
                    }
                }

            }

            System.out.println();

        }

    }

    public static void main(String[] args) {
        
        Graph graph = new Graph(3);
        graph.display();

        //Recurssion Dfs
        System.out.print("Dfs Traversal:");
        graph.dfs(0);
        System.out.println();


        //Iterative Order Traversal;
        graph.dfsRecurssiveTraversal(0);
        System.out.println();
        return;
    }
}
