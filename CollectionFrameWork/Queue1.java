import java.util.*;
public class Queue1{
    public static void main(String[] args){
        Queue<Integer>queue = new LinkedList<Integer>();

        queue.add(1);

        while(!queue.isEmpty()){
            int val = queue.peek();
            queue.poll();
            System.out.printf("val:%d",val);
        }
    }
}