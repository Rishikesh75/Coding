import java.util.*;
public class LinkedList1{
    public static void main(String[] args){
        List<Integer> list = new LinkedList<>();

        list.addFirst(1);
        list.addLast(2);

        System.out.printf("%d\t%d\n",list.getFirst(),list.getLast());

        Iterator<Integer> it = list.iterator();

        while(it.hasNext()){
            System.out.printf("%d\t",it.next());
        }

        list.removeFirst();
        list.removeLast();
    }
}