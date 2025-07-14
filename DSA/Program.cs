using System;
using System.ComponentModel.Design.Serialization;
using System.Diagnostics.Contracts;
using System.Runtime.InteropServices;
using System.Security.Cryptography.X509Certificates;
namespace DSA
{

    public class LinkedList
    {
        public class Node
        {
            public int value;
            public Node Next;

            public Node(int value)
            {
                this.value = value;
                this.Next = null;
            }

        }
        private Node Head;
        private Node Tail;

        public void CreateList()
        {
            Head = null;
            Tail = null;
        }

        public Node CreateNode(int value)
        {
            Node newNode = new Node(value);
            return newNode;
        }

        public void InsertNodeLast(int value)
        {
            Node NewNode = CreateNode(value);
            if (Head == null && Tail == null)
            {
                Head = NewNode;
                Tail = NewNode;
            }
            else
            {
                Tail.Next = NewNode;
                Tail = NewNode;
            }
        }

        public void RemoveNodeFirst()
        {
            if (Head == Tail)
            {
                Head = null;
                Tail = null;
            }
            else
            {
                Head = Head.Next;
            }
        }

        public void Display()
        {
            Node temp = Head;
            while (temp != null)
            {
                Console.Write($"{temp.value}\t");
                temp = temp.Next;
            }
            Console.WriteLine();
        }

    }

    public class Stack
    {
        public class Node
        {
            public int Value;
            public Node? Next;
        }
        private Node? top;
        public void CreateStack()
        {
            top = null;
        }
        public Node CreateNode(int value)
        {
            Node NewNode = new Node();
            NewNode.Value = value;
            NewNode.Next = null;
            return NewNode;
        }
        public void InsertElement()
        {
            int.TryParse(Console.ReadLine(), out int value);
            Node NewNode = CreateNode(value);
            if (top == null)
            {
                top = NewNode;
            }
            else
            {
                NewNode.Next = top;
                top = NewNode;
            }
        }
        public void DisplayStack()
        {
            Node temp = top;
            if (temp == null)
            {
                Console.WriteLine("Stack is Empty");
                return;
            }
            while (temp != null)
            {
                Console.WriteLine($"{temp.Value}");
                temp = temp.Next;
            }
        }
    }

    public class Queue
    {
        public class Node
        {
            public int value;

            public Node Next;

            public Node(int value)
            {
                this.value = value;
                Next = null;
            }

        }

        private Node head;
        private Node tail;

        public Queue()
        {
            head = null;
            tail = null;
        }

        public Node CreateNode(int value)
        {
            Node NewNode = new Node(value);
            return NewNode;
        }
        public void InsertNode()
        {
            int.TryParse(Console.ReadLine(), out int value);
            Node NewNode = CreateNode(value);
            if (head == null && tail == null)
            {
                head = NewNode;
                tail = NewNode;
            }
            else
            {
                tail.Next = NewNode;
                tail = NewNode;
            }
        }
        public void DisplayQueue()
        {
            Node temp = head;
            while (temp != null)
            {
                Console.Write($"{temp.value}\t");
                temp = temp.Next;
            }
            Console.WriteLine();

        }
    }

    public class Tree
    {
        public class Node
        {

            public int value;
            public Node Left;
            public Node Right;
            public Node(int value)
            {
                this.value = value;
                Left = null;
                Right = null;
            }
        }
        public Node Root = null;
        
        public Node CreateNode(int value)
        {
            Node NewNode = new Node(value);
            return NewNode;
        }

        public Node CreateTree()
        {
            Console.WriteLine("Enter the Value");
            int.TryParse(Console.ReadLine(), out int value);
            Node NewNode = CreateNode(value);
            if (Root == null)
            {
                Root = NewNode;
            }
            Console.WriteLine("Enter Y if there is Left Child Else N:");
            Char.TryParse(Console.ReadLine(), out char childLeft);
            if (childLeft == 'Y')
            {
                NewNode.Left = CreateTree();
            }
            Console.WriteLine("Enter Y if there is Right Child Else N:");
            Char.TryParse(Console.ReadLine(), out char childRight);
            if (childRight == 'Y')
            {
                NewNode.Right = CreateTree();
            }
            return NewNode;
        }

        public void DisplayInorderTraversal(Node Root)
        {
            if (Root == null)
            {
                return;
            }
            Console.WriteLine($"{Root.value}");
            DisplayInorderTraversal(Root.Left);
            DisplayInorderTraversal(Root.Right);
        }

    }

    public class Graph
    {
        public int Vertices;
        public List<List<int>> Edges;

        public void CreateGraph()
        {
            Edges = new List<List<int>>();
            for (int i = 0; i < Vertices; i++)
            {
                Edges.Add(new List<int>());
                for (int j = 0; j < Vertices; j++)
                {
                    Console.WriteLine($"Edge{i} b/w {j}:");
                    char.TryParse(Console.ReadLine(), out char value);
                    if (value == 'Y')
                    {
                        Edges[i].Add(j);
                    }
                }
            }
        }

        public void Display()
        {
            for (int i = 0; i < Edges.Count; i++)
            {
                Console.Write($"{i}:");
                for (int j = 0; j < Edges[i].Count; j++)
                {
                    Console.Write($"{Edges[i][j]}\t");
                }
                Console.Write("\n");
            }
        }
        void Intializearr(ref List<int> Visited_arr, int Vertices)
        {
            for (int i = 0; i < Vertices; i++)
            {
                Visited_arr.Add(0);
            }
        }
        void pushNodes(int temp, ref Queue<int> queue, List<List<int>> Edges,ref List<int> Visted_arr)
        {
            for (int i = 0; i < Edges[temp].Count; i++)
            {
                if (Visted_arr[Edges[temp][i]] == 0)
                {
                    queue.Enqueue(Edges[temp][i]);
                    Visted_arr[Edges[temp][i]] = 1;
                }
                
            }
        }
        public void BFS()
        {
            List<int> Visted_arr = new List<int>();
            Intializearr(ref Visted_arr, Vertices);
            Queue<int> queue = new Queue<int>();
            queue.Enqueue(0);
            Visted_arr[0] = 1;
            while (queue.Count != 0)
            {
                int temp = queue.Dequeue();
                pushNodes(temp, ref queue, Edges, ref Visted_arr);
                Console.Write($"{temp}");
            }
            Console.WriteLine();

        }

    }




    public class Program
    {
        public static void Main(string[] args)
        {
            // LinkedList linkedList = new LinkedList();
            // linkedList.CreateList();
            // linkedList.InsertNodeLast(1);
            // linkedList.Display();
            // Stack S1 = new Stack();
            // S1.CreateStack();
            // S1.InsertElement();
            // S1.DisplayStack();
            // Queue queue = new Queue();
            // queue.InsertNode();
            // queue.InsertNode();
            // queue.DisplayQueue();
            // Tree tree = new Tree();
            // tree.CreateTree();
            // tree.DisplayInorderTraversal(tree.Root);
            Graph graph = new Graph();

            graph.Vertices = 3;
            graph.CreateGraph();
            graph.Display();
            graph.BFS();
        }
    }


}
