
import java.util.LinkedList;
import java.util.Queue;

public class Queue1
{
    public static void main(String[] args) {
    
        Queue<Integer> queue = new LinkedList<Integer>();

        queue.add(1);
        queue.peek();
        queue.poll();
        queue.isEmpty();
    }
}