//Path-Based-Patterns5
import java.util.*;
public class TreeJava5
{
    public static class Node
    {
        public Integer val;
        public Node left;
        public Node right;

        Node(int val)
        {
            this.val = val;
            this.left = null;
            this.right = null;
        }
    }

    public static Node createNode(int val)
    {
        return new Node(val);
    }

    public static Node createTree()
    {
        Node root =  createNode(1);

        root.left = createNode(2);

        root.right = createNode(3);

        return root;
    }

    public static List<List<Integer>> paths = new ArrayList<>();
    public static void rootToPath(Node root,List<Integer>path)
    {
        if(root == null) return;
        path.add(root.val);

        if(root.left == null && root.right == null)
        {
            paths.add(new ArrayList<>(path));
        }

        else
        {
            rootToPath(root.left,path);
            rootToPath(root.right,path);
        }

        path.remove(path.size()-1);

        return;
    }

    public static void displayPaths()
    {
        for(var path : paths)
        {
            for(var i : path)
            {
                System.out.printf("%d\t",i);
            }
            System.out.println();
        }
    }
    public static void main(String[] args)
    {
//        System.out.println("Helllooo");
        Node root = createTree();
        rootToPath(root,new ArrayList<Integer>());
        displayPaths();
    }
}