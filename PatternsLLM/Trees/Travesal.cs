public class Progarm
{
    public  class Node
    {
        public int Val;

        public Node Left;

        public Node Right;

        public Node(int val)
        {
            this.Val = val;
            this.Left = null;
            this.Right = null;
        }
    }

    public static Node? CreateNode(int n)
    {
        return new Node(n);
    }

    public static Node? CreateTree()
    {
        Node root = CreateNode(1);

        root.Left = CreateNode(2);

        root.Right = CreateNode(3);

        return root;

    }
    
    public static void InorderTraversal(Node? root)
    {
        if(root == null) return;
        InorderTraversal(root.Left);
        Console.Write($"{root.Val}\t");
        InorderTraversal(root.Right);
    }

    public static void PreOrderTraversal(Node? root)
    {
        if(root == null) return;
        Console.Write($"{root.Val}\t");
        PreOrderTraversal(root.Left);
        PreOrderTraversal(root.Right);
    }

    public static void  PostOrderTraversal(Node? root)
    {
        if(root == null) return;
        PostOrderTraversal(root.Left);
        PostOrderTraversal(root.Right);
        Console.Write($"{root.Val}\t");
    }

    
    public static void Main(string[] args)
    {
        Node? root = CreateTree();

        Console.WriteLine("----InordreTraversal----");
        InorderTraversal(root);
        Console.WriteLine();

        Console.WriteLine("----PreOrderTraversal----");
        PreOrderTraversal(root);
        Console.WriteLine();

        Console.WriteLine("----PosttOrderTraversal----");
        PostOrderTraversal(root);
        Console.WriteLine();
    }
}