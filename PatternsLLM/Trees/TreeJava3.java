import java.util.*;
public class TreeJava3
{
    public static class Node
    {
        public int val;
        public Node left;
        public Node right;

        Node(int val)
        {
            this.val = val;
            left = null;
            right = null;
        }
    }

    public static Node createNode(int val)
    {
        return new Node(val);
    }

    public static Node createTree()
    {
        Node root = createNode(1);

        root.left = createNode(2);

        root.right= createNode(3);

        root.left.left = createNode(2);

        root.right.right= createNode(3);
        return root;
    }

    public static void levelOrderTraversal(Node root)
    {
        Queue<Node>queue = new  LinkedList<>();

        queue.add(root);

        while(!queue.isEmpty())
        {
            var top = queue.peek();
            queue.poll();

            System.out.printf("%d",top.val);

            if(top.left != null)
                queue.add(top.left);
            if(top.right != null)
                queue.add(top.right);
        }

        return;
    }
    public static class MyPair
    {
        Node node;
        boolean LR ;

        MyPair(Node node,boolean LR)
        {
            this.node = node;
            this.LR  = LR;
        }
    }
    public static void zigZagTraversal(Node root)
    {
        Queue<MyPair>queue = new LinkedList<>();

        queue.add(new MyPair(root,false));

        while(!queue.isEmpty())
        {
            List<MyPair> list = new LinkedList<>();
            boolean val= false;
            while(!queue.isEmpty())
            {
                var top = queue.peek();
                val = top.LR;
                queue.poll();
                list.add(top);
            }
            if(!val) Collections.reverse(list);;

            for(var item : list)
            {
                System.out.printf("%d",item.node.val);
                if(item.node.left != null)
                    queue.add(new MyPair(item.node.left,!item.LR));
                if(item.node.right != null)
                    queue.add(new MyPair(item.node.right,!item.LR));
            }

        }
        return ;

    }
    public static Map<Integer,List<Integer>> map = new HashMap<>();
    public static  void LeftView(Node root)
    {
        Build(root,0);

        for(var item : map.entrySet())
        {
            System.out.printf("\t%d:%d",item.getKey(),item.getValue().get(0));
        }
    }

    public static  void RightView(Node root)
    {
//        Build(root,0);

        for(var item : map.entrySet())
        {
            System.out.printf("\t%d :%d",item.getKey(),item.getValue().get(item.getValue().size()-1));
        }
    }
    public static double Average(List<Integer>list)
    {
        int sum = 0;
        for(var item : list)
        {
            sum = sum + item;
        }
        return (double) sum / list.size();

    }
    public static void AverageLevels()
    {
        for(var item : map.entrySet())
        {
            System.out.printf("\t%d : %f",item.getKey(),Average(item.getValue()));
        }
    }
    public static void LevelOrderSucessor()
    {
        System.out.println();
        for(var item : map.entrySet())
        {
            for(var i : item.getValue())
            {
                System.out.printf("%d\t",i);
            }

        }
    }
    public static void Build(Node root,int level)
    {
        if(root == null) return;
        if(map.containsKey(level))
            map.get(level).add(root.val);
        else
            map.put(level,new LinkedList<Integer>(List.of(root.val)));

        Build(root.left,level+1);
        Build(root.right,level+1);
    }
    public static void main(String[] args)
    {
        System.out.println("Hellooo TREES");
        var root = createTree();
//        levelOrderTraversal(root);
        zigZagTraversal(root);
        LeftView(root);
        RightView(root);
        AverageLevels();
        LevelOrderSucessor();
    }
}