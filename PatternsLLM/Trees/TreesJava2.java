import java.util.*;
public class TreesJava2
{
    public static class Node
    {
        int val;
        Node left;
        Node right;

        Node(int val)
        {
            this.val = val;
            left = null;
            right = null;
        }
    }

    public static Node createNode(int val)
    {
        Node node = new Node(val);
        return node;
    }

    public static Node createTree()
    {
        Node root = createNode(1);

        root.left = createNode(2);

        root.right = createNode(3);

        root.left.left = createNode(2);

        return root;
    }

    public static int depthBinaryTree(Node root)
    {
        if(root == null) return 0;

        int depth = 1+Math.max(depthBinaryTree(root.left),depthBinaryTree(root.right));

        return depth;
    }
    public static void main(String[] args)
    {
        Node root = createTree();

        System.out.printf("%d",depthBinaryTree(root));
    }
}