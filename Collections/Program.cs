using System;
using System.Collections;
using System.Runtime.InteropServices;
namespace Collections
{
    public class Program
    {
        public static void ArrayList()
        {
            ArrayList List = new ArrayList();
            List.Add("10");
            List.Add("20");
            for(int i=0;i<List.Count;i++)
            {
                Console.Write($"{List[i]}\t");
            }        
            Console.Write("\n");   
            Console.WriteLine($"{List.Count}");
            Console.WriteLine($"{List.IndexOf("10")}");
            List.RemoveAt(List.IndexOf("10"));
            List.Remove(List[0]);
            Console.WriteLine($"{List.Count}");
            int pos = 1;
            int value = 100;
            List.Insert(pos, value);
        }
        public static void HashTable()
        {
            Hashtable ht = new Hashtable();
            ht.Add("Rishikesh",40);
            foreach(DictionaryEntry keyvalue in ht)
            {
                Console.WriteLine($"{keyvalue.Key}:{keyvalue.Value}");
            }
            ht.Remove("Rishikesh");
        }
        public static void SortedList()
        {
            SortedList srtList = new SortedList();
            srtList.Add("a",1);
            Console.WriteLine($"{srtList.Count}");
            foreach(DictionaryEntry elem in srtList)
            {
                Console.WriteLine($"{elem.Key}:{elem.Value}");
            }
        }
        public static void Stack()
        {
            Stack s = new Stack();
            s.Push("10");
            
        }


        public static void ListGeneric()
        {
            List<int> arr1 = new List<int>();
            int n = 10;
            for (int i = 0; i < n; i++)
            {
                int.TryParse(Console.ReadLine(), out int value);
                arr1.Add(value);


            }
            arr1.Insert(1, 10);
            arr1.Insert(11, 100);
            arr1.Remove(10);//Remove Value first occurance of the value
                            //Removeat at the particular positon
            for (int i = 0; i < arr1.Count; i++)
            {
                Console.Write($"{arr1[i]}\t");
            }
            
            Console.WriteLine();
        }
        public static void LinkedList()
        {
            LinkedList<int> linkedlist = new LinkedList<int>();
            linkedlist.AddFirst(10);
            linkedlist.AddFirst(20);
            LinkedListNode<int> CurrentNode = linkedlist.First;
            while (CurrentNode != null)
            {
                Console.WriteLine($"{CurrentNode.Value}");
                CurrentNode = CurrentNode.Next;
            }
        }
        public static void StackGeneric()
        {
            Stack<int> s = new Stack<int>();
            s.Push(1);
            s.Push(2);
            while (s.Count != 0)
            {
                Console.WriteLine($"{s.Peek()}");
                s.Pop();
            }
        }

        public static void QueueGeneric()
        {
            Queue<int> q_1 = new Queue<int>();
            q_1.Enqueue(10);
            //q_1.Dequeue();
            Console.WriteLine($"{q_1.Count}");
            while (q_1.Count != 0)
            {
                var varible = q_1.Dequeue();
                Console.WriteLine($"{varible}");
            }
        }
        public static void insertQueue(ref LinkedList<(int, int)> q, (int, int) value)
        {
            LinkedListNode<(int, int)> Head = q.First;
            if (Head == null)
            {
                q.AddFirst(value);
                return;
            }
            while (Head != null)
            {
                    if (Head.Value.Item1 < value.Item1)
                    {
                        q.AddBefore(Head, value);
                    }
                    Head = Head.Next;
            }
        }
        public static void DisplayQueue(LinkedList<(int, int)> q)
        {
            LinkedListNode<(int, int)> Head = q.First;
            while (Head != null)
            {
                Console.Write($"{Head.Value.Item2}\t");
                Head = Head.Next;
            }
            Console.WriteLine();
        }
        public static void QueueGenericPriority()
        {
            LinkedList<(int, int)> q_1 = new LinkedList<(int, int)>();
            (int, int) value = (1, 2);
            insertQueue(ref q_1, value);
            value = (10, 3);
            insertQueue(ref q_1, value);
            DisplayQueue(q_1);
            DisplayQueue(q_1);
         }
        public static void PriorityQueue()
        {
            PriorityQueue<int, int> pq = new PriorityQueue<int, int>(Comparer<int>.Create((a, b) => a.CompareTo(b)));
            pq.Enqueue(1, 10);
            pq.Dequeue();
        }
        
            public static void Main(string[] args)
        {

            // ArrayList();
            // HashTable();
            // SortedList();
            //ListGeneric();
            //LinkedList();
            //StackGeneric();
            //QueueGeneric();
            QueueGenericPriority();
        }   
    }
}
