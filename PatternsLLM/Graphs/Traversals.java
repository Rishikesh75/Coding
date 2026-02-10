import java.util.*;
public class Traversals
{
    public static List<List<Integer>> createGraph()
    {
        List<List<Integer>> list = new ArrayList<>();

        for(int i=0;i<3;i++)
        {
            list.add(new ArrayList<Integer>());
        }

        list.get(0).add(1);
        list.get(0).add(2);


        return list;
    }

    public static void displayGraph(List<List<Integer>>list)
    {
        for(var edges : list)
        {
            for(var node : edges)
            {
                System.out.printf("%d\t",node);
            }
            System.out.println();
        }
    }

    public static void dfsTraversal(List<List<Integer>> list,int startNode,List<Integer> visitedArr) {

//        List<Integer> visitedArr =new ArrayList<>(Collections.nCopies(list.size(), 0));

        Stack<Integer> stack = new Stack<>();

        stack.push(startNode);
        visitedArr.set(startNode, 1);

        while (!stack.isEmpty()) {
            int top = stack.pop();
            System.out.print(top + " ");

            for (int node : list.get(top)) {
                if (visitedArr.get(node) == 0) {
                    stack.push(node);
                    visitedArr.set(node, 1);
                }
            }
        }
        return;
    }

    public static void bfsTraversal(List<List<Integer>> list,int startNode,List<Integer> visitedarr)
    {
//        List<Integer> visitedarr = new ArrayList<>(Collections.nCopies(list.size(),0));

        Queue<Integer> queue = new LinkedList<>();

        queue.add(startNode);
        visitedarr.set(startNode,1);

        while(!queue.isEmpty())
        {
            int top = queue.peek();
            queue.poll();
//            System.out.print(top + " ");

            for(int node : list.get(top)){
                if(visitedarr.get(node) == 0){
                    queue.add(node);
                    visitedarr.set(node,1);
                }
            }
        }
        return;
    }

    public static void noOfConnectedComponents(List<List<Integer>> list)
    {
        List<Integer> visitedarr = new ArrayList<>(Collections.nCopies(list.size(),0));
        int count = 0;
        for(int i=0;i<list.size();i++)
        {

            if(visitedarr.get(i) == 0)
            {
                count++;
                bfsTraversal(list,i,visitedarr);
            }

        }
        System.out.println();
        System.out.printf("no of connected components :%d",count);

    }

    public static void main(String[] args)
    {
        var graph = createGraph();

        displayGraph(graph);

//        dfsTraversal(graph);
//
//        bfsTraversal(graph);
        noOfConnectedComponents(graph);

    }
}