import java.util.*;
public class set1{
    public static void main(String[] args){

        Set<Integer> set = new HashSet<>();

        set.add(1);

        for(var num : set){
            System.out.printf("%d",num);
        }
        set.remove(1);


    }
}