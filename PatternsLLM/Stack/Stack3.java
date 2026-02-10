import java.util.*;
public  class Stack3
{
    public static class QueuePair
    {
        public Queue<Integer> queue1 = new LinkedList<>();

        public Queue<Integer> queue2 = new LinkedList<>();
    }
    public static class Stack
    {
        public QueuePair queuePair = new QueuePair();

        public void push(int val)
        {
            queuePair.queue2.add(val);

            while(!queuePair.queue1.isEmpty())
            {
                val = queuePair.queue1.peek();
                queuePair.queue1.poll();
                queuePair.queue2.add(val);
            }

            swapQueuePair();
        }

        public void swapQueuePair()
        {
            var temp = queuePair.queue1;
            queuePair.queue1 = queuePair.queue2;
            queuePair.queue2 = temp;
        }

        public void display()
        {
            for(var item : queuePair.queue1)
            {
                System.out.printf("%d\n",item);
            }
        }
    }
    public static void main(String[] args)
    {
        System.out.println("Helloo Java...");

        Stack stack = new Stack();

        stack.push(1);

        stack.push(3);

        stack.display();
    }

}