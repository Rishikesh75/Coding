import java.util.*;
public class Map1{
    public static void main(String[] args){

        Map<Integer,Integer> map = new HashMap<>();
        map.put(1,1);

        System.out.printf("%d\n",map.get(1));
        System.out.printf("%b\n",map.isEmpty());

        var keys = map.keySet();
        for(var key : keys){
            System.out.printf("value:%d",key);
        }
       for(Map.Entry<Integer,Integer> value : map.entrySet()){
           System.out.printf("%d %d",value.getKey(),value.getValue());

           map.remove(1);
       }
    }
}