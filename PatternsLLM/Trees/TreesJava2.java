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

    public static int maxDepthBinaryTree(Node root)
    {
        if(root == null) return 0;

        int depth = 1+Math.max(maxDepthBinaryTree(root.left),maxDepthBinaryTree(root.right));

        return depth;
    }
    public static int minDepthBinaryTree(Node root)
    {
        if(root == null) return 0;

        int depth = 1+Math.min(minDepthBinaryTree(root.left),minDepthBinaryTree(root.right));

        return depth;
    }
    public static boolean sameTree(Node root1,Node root2)
    {
        if(root1 == null && root2 == null) return true;

        if(root1 == null || root2 == null ) return false;

        if(root1.val != root2.val) return false;

        return sameTree(root1.left,root2.left) && sameTree(root2.right,root2.right);
    }
    public static boolean symetricTreeRecurssion(Node root1,Node root2)
    {
        if(root1 == null && root2 == null ) return true;

        if(root1 == null || root2 == null) return false;

        if(root1.val != root2.val) return false;

        return symetricTreeRecurssion(root1.left,root2.right) && symetricTreeRecurssion(root1.right,root2.left);
    }
    public static boolean symetricTree(Node root)
    {
        if(root == null || (root.left == null && root.right == null)) return true;

        return symetricTreeRecurssion(root.left,root.right);

    }
    public static  int sum = 0;
    public static boolean pathSum1(Node root,int k)
    {
        if(root == null)
            if(sum == k)
                return true;
            else
                return false;

        sum = sum + root.val;
        var bleft =  pathSum1(root.left,k);
        var bright =  pathSum1(root.right,k);
        sum = sum - root.val;
        return bleft || bright;
    }
    public static Map<Integer,Integer> map = new HashMap<>();
    public static boolean pathSum3(Node node,int k,int sum)
    {
        if(node == null)
            return false;
        sum = sum + node.val;
        if(map.containsKey(k-sum))
        {
            return true;
        }
        map.put(sum,1);
        boolean left = pathSum3(node.left,k,sum) ;
        boolean right = pathSum3(node.right,k,sum);

        map.remove(sum);

        return left || right;
    }
    public static void main(String[] args)
    {
        Node root = createTree();

        System.out.printf("%d",maxDepthBinaryTree(root));

        System.out.printf("%d",minDepthBinaryTree(root));

        System.out.printf("%b",sameTree(root,root));

        System.out.printf("%b",symetricTree(root));

        System.out.printf("%b",pathSum1(root,4));

        System.out.printf("%b",pathSum3(root,4,0));
    }
}