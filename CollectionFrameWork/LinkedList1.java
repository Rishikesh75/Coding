
import java.util.LinkedList;

public class LinkedList1{


    public static void main(String[] args){
        LinkedList<Integer> linkedlist = new LinkedList<>();

        linkedlist.addFirst(1);
        linkedlist.addLast(1);


        linkedlist.getFirst();
        linkedlist.getLast();

        linkedlist.removeFirst();
        linkedlist.removeLast();

        linkedlist.set(1,1);
        linkedlist.get(11);
        linkedlist.remove(1);
        
        //iterator() hasNext() next()

        return;
    }
}