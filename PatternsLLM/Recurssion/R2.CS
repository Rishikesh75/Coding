using System;
using System.Collections.Generic;

public class Program
{
    public  class Node
    {
        public int Val;

        public Node Left;

        public Node right;

        public Node(int val)
        {
            this.Val = val;
            Left = null;
            right = null;
        }

    }
    
    public static Node CreateTree()
    {
        Node root = new Node(1);

        root.Left = new Node(2);

        root.right = new Node(2);

        return root;
    }
    public static int Fib(int n)
    {
        if(n == 1)
            return 0;

        if(n ==2)
            return 1;

        return Fib(n-1) + Fib(n-2);
    }
    
    public static int HeightBinaryTree(Node root)
    {
        if(root == null)
            return 0;

        int left = HeightBinaryTree(root.Left);

        int right = HeightBinaryTree(root.right);

        return 1 + Math.Max(left,right);
    }

    public static int MaxDiameter = 0;
    public static int DiameterOfBianryTree(Node root)
    {
        if(root == null)
            return 0;
        
        int left = DiameterOfBianryTree(root.Left);

        int right = DiameterOfBianryTree(root.right);

        Console.WriteLine($"left:{left} right:{right}");

        MaxDiameter = Math.Max(MaxDiameter,left+right+1);

        return 1+Math.Max(left,right);
    }
    public static void Main(string[] args)
    {
        
        int.TryParse(Console.ReadLine(),out int n);
        Console.WriteLine($"{Fib(n)}");

        var root = CreateTree();
        Console.WriteLine($"HeightOfBinaryTree:{HeightBinaryTree(root)-1}");

        DiameterOfBianryTree(root);
        Console.WriteLine($"Max Dimater:{MaxDiameter}");
    }
}