import java.util.*;
public class Stack1
{
    public static class Stack
    {
        private static List<Integer> list;

        Stack()
        {
            list = new ArrayList<Integer>();
        }

        public static void push(int val)
        {
            list.add(val);
        }

        public static void pop()
        {
            list.remove(list.size()-1);
        }

        public static int peek()
        {
            return list.get(list.size()-1);
        }

        public static void display()
        {
            for(var item : list)
            {
                System.out.printf("%d\t", item);
            }
            System.out.println();
        }
    }

    public static void main(String[] args)
    {
        Stack stack = new Stack();

        stack.push(1);
        stack.push(2);

        System.out.printf("Peekvalue:%d\n",stack.peek());
        stack.display();
    }
}