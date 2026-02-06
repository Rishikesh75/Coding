//Height or Depth patterns
import java.util.*;
public class TreeJava4
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

    public static Node createNode(int n)
    {
        return new Node(n);
    }

    public static Node createTree()
    {
        Node root = new Node(1);

        root.left = new Node(3);
        root.right = new Node(2);


        root.left.left = new Node(3);
        return root;
    }

    public static int heightTree(Node root)
    {
        if(root == null) return 0;

        int left = heightTree(root.left) + 1;

        int right = heightTree(root.right) + 1;

        return Math.max(left,right);
    }
    private static int maxDiameter = 0;
    public static int diameterBinaryTree(Node root)
    {
        if(root == null) return 0;

        int left = 1+diameterBinaryTree(root.left);
        int right = 1+diameterBinaryTree(root.right);

        maxDiameter = Math.max(maxDiameter,right+left-1);
        return Math.max(left,right);
    }

    public static boolean isBalancedBinaryTree = true;
    public static int balancedBinaryTree(Node root)
    {
        if(root == null) return 0;
        int left = heightTree(root.left) + 1;
        int right = heightTree(root.right) + 1;

        if(isBalancedBinaryTree)
        {
            if(Math.abs(left-right)+1>1)
            {
                isBalancedBinaryTree = false;
                return -1;
            }

        }
        return Math.max(left,right);
    }

    public static int maxPathSum = 0;
    public static int pathSum(Node root)
    {
        if(root == null) return 0;

        int leftval = pathSum(root.left);
        int rightval = pathSum(root.right);

        maxPathSum =  Math.max(maxPathSum , root.val + leftval + rightval);

        return root.val+leftval+rightval;
    }
    public static void main(String[] args)
    {
        Node root = createTree();

        System.out.printf("%d\n",heightTree(root));

        diameterBinaryTree(root);
        System.out.printf("%d\n",maxDiameter);

        balancedBinaryTree(root);
        System.out.printf("%b\n",isBalancedBinaryTree);

        pathSum(root);
        System.out.printf("%d\n",pathSum(root));
    }
}