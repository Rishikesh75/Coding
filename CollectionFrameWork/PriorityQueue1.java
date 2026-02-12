import java.util.*;
public class PriorityQueue1{
    public static void main(String[] args){
        PriorityQueue<Integer>pq = new PriorityQueue<>((Integer a,Integer b) -> {return a - b;});

        pq.add(2);
        pq.add(1);


        while(!pq.isEmpty()){
            int val = pq.peek();
            pq.poll();
            System.out.printf("val:%d",val);
        }

    }
}