import java.util.*;
public class Stack2
{
    public static class Stack
    {
        public  List<Integer> list;

        Stack()
        {
            list = new LinkedList<Integer>();
        }

        public   void push(int value)
        {
            list.addLast(value);
        }

        public  void pop()
        {
            list.removeLast();
        }

        public  int peek()
        {
            return list.getLast();
        }

        public  void display()
        {
            for(var item : list)
            {
                System.out.printf("%d\t",item);
            }
        }
    }
    public static void main(String[] args)
    {
        Stack stack = new Stack();

        stack.push(1);
        stack.push(2);

        stack.display();
    }

}