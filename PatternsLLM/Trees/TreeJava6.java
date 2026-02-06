import java.util.*;
public class TreeJava6
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

    public static Node createNode(int n)
    {
        return new Node(n);
    }

    public static Node createTree()
    {
        Node root = createNode(1);

        root.left = createNode(2);

        root.right = createNode(3);

        return root;
    }

    private static Node ans;
    private static boolean val1bool = false;
    private static boolean val2bool = false;
    public static void lCA(Node node,int val1,int val2)
    {
        if(node == null)
            return;

        lCA(node.left,val1,val2);
        lCA(node.right,val1,val2);

        if(val1bool && val2bool)
        {
            ans = node;
            return;
        }
        if(node.val == val1)
            val1bool =  true;
        if(node.val == val2)
            val2bool = true;

        return ;
    }

    public static int findDistance(Node root,int val1)
    {
        if(root == null) return -1;
        if(root.val == val1)
            return root.val;

        int left = findDistance(root.left, val1);
        int right = findDistance(root.right, val1);

        if(left != -1) return root.val + left;
        if(right != -1) return root.val + right;

        return -1;
    }

    public static Node ansKth ;
    public static void lCAKth(Node node,int val1,int val2,int k)
    {
        if(node == null)
            return;

        lCAKth(node.left,val1,val2,k);
        lCAKth(node.right,val1,val2,k);

        if(val1bool && val2bool)
        {
            k--;
            if(k == 0)
            {
                ansKth = node;
            }

        }
        if(node.val == val1)
            val1bool =  true;
        if(node.val == val2)
            val2bool = true;

        return ;
    }
    public static void main(String[] args)
    {
        Node root = createTree();

        lCA(root,2,3);

        System.out.printf("lca:%d",ans.val);

        System.out.printf("value:%d",findDistance(ans,2)+findDistance(ans,3)-ans.val);

        lCAKth(root,2,3,1);
        System.out.printf("%d",ansKth.val);


    }
}