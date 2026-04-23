
import java.util.HashSet;
import java.util.List;
import java.util.Set;



public class Set1
{
    public static void main(String[] args)
    {

       Set<Integer> set = new HashSet<>();

       set.add(1);
       set.remove(1);

       set.contains(1);

       set.retainAll(List.of(1,2,3,4));
       set.removeAll(List.of(1,1,1,1));
    }
}