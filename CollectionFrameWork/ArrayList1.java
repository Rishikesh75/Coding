
import java.util.ArrayList;
import java.util.List;

public class ArrayList1{


    public static void display(List<Integer> list){

        System.out.print("value:");
        for(var val : list){
            System.out.printf("%d",val);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        
        List<Integer> list = new ArrayList<>();


        list.add(1);
        list.add(1,1);


        list.addAll(1,List.of(1,2,3,4));
        list.addAll(List.of(1,2,3,4,5));


        list.remove(1);
        list.remove(Integer.valueOf(1));
        list.removeIf((x) -> x == 1);
        list.subList(1, 2).clear();


        list.get(1);
        list.set(1,2);

        list.sort((x1,x2)-> x1 - x2);


        return;
    }
}