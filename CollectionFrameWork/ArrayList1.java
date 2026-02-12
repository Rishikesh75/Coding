import java.util.*;
public class ArrayList1
{
    public static void main(String[] args){
        List<Integer> list = new ArrayList<>();

        //Adding the value
        list.add(1);
        list.add(2);

        //Add (Index,value)
        list.add(1,1);

        //Remove the index
        list.remove(1);

        //get the index the value
        System.out.printf("value:%d\n",list.get(1));

        //Iterator
        Iterator<Integer> it = list.iterator();
        while(it.hasNext()){
            System.out.printf("%d\t",it.next());
        }
        System.out.println();
        list.set(1,3);

        System.out.printf("Size:%d",list.size());

//      List<Integer> list1 = list.clone();

    }
}