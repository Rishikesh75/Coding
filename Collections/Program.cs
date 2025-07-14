using System;
using System.Collections;
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
            //Insert(pos,value)
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
        public static void Main(string[] args)
        {

            ArrayList();
            HashTable();
            SortedList();
        }   
    }
}
