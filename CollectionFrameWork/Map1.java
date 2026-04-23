
import java.util.HashMap;
import java.util.Map;


public class Map1
{
    public static void main(String[] args)
    {


        Map<Integer,Integer> map = new HashMap<>();

        map.put(1,1);

        map.containsKey(1);
        map.remove(1);
        map.replace(1, 1);
        map.get(1);
        map.entrySet();

        //getKey() getValue()

        return;
    }

}