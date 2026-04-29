import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
public class Array1
{
    public static class Pair{
        public Integer first;
        public Integer second;

        public Pair(Integer first,Integer second){
            this.first = first;
            this.second = second;
        }
    }



    public static Pair findLargestAndSmallest(List<Integer> list){
        Pair pair = new Pair(Integer.MAX_VALUE, Integer.MIN_VALUE);

        for(var val : list){
            pair.first = Math.min(pair.first,val);
            pair.second = Math.max(pair.second,val);
        }

        System.out.printf("Smallest:%d\tLargest:%d\n",pair.first,pair.second);

        return pair;
    }

    public static int findSecondLargest(List<Integer> list){
        int firstLargest = list.get(0);
        int secondLargest = Integer.MAX_VALUE;

        for(int i=1;i<list.size();i++){
            if(list.get(i) > firstLargest){
                secondLargest = firstLargest;
                firstLargest = list.get(i);
            }

            else if(list.get(i) > secondLargest){
                secondLargest = list.get(i);
            }
        }

        System.out.printf("Second Largest:%d\n",secondLargest);
        return secondLargest;
    }

    public static Boolean checkSortedArray(List<Integer> list){

        for(int i=1;i<list.size();i++){
            if(list.get(i-1) > list.get(i))
                return false;
        }

        return true;
    }
    
    public static Pair countEvenOrOdd(List<Integer> list){
        Pair pair = new Pair(0, 0);

        for(var val : list){
            if(val %2 == 0)
                pair.first++;
            else
                pair.second++;
        }

        System.out.printf("Even Count:%d Odd Count:%d\n",pair.first,pair.second);
        return pair;
    }

    public static void display(List<Integer> list){

        System.out.print("values:");
        for(var val : list){
            System.out.printf("%d\t",val);
        }
        System.out.println();
    }

    public static void reverseArray(List<Integer> list){

        int i = 0;
        int j = list.size()-1;

        while(i<j){
            int val = list.get(i);
            list.set(i,list.get(j));
            list.set(j,val);

            i++;
            j--;
        }

    }

    public static boolean isPlamindrome(List<Integer> list){
        int i = 0;
        int j = list.size()-1;

        while(i<j){
            
            if(list.get(i) != list.get(j))
                return false;

            i++;
            j--;
        }

        return true;
    }

    public static void countFrequency(List<Integer> list){
        Map<Integer,Integer> map = new HashMap<>();

        for(var val : list){
            if(map.containsKey(val))
                map.replace(val,map.get(val)+1);
            else    
                map.put(val, 1);
        }

        System.out.print("Frequency values:\t");
        for(var entry : map.entrySet()){
            System.out.printf("%d %d\t",entry.getKey(),entry.getValue());
        }
        System.out.println();
    }

    public static int findMissingNumber(List<Integer> list){
        int sum = 0;


        for(int i =0;i<list.size();i++){
            sum += list.get(i);
        }

        return  (((list.size()) * (list.size() + 1)) / 2) - sum;
    }

    public static void removeDuplicate(List<Integer> list){

        list.sort((Integer val1,Integer val2) -> val1 - val2);

        
        int lastvalidIndex = 0;
        int i = lastvalidIndex + 1;

        while(i<list.size()){
            if(list.get(i) != list.get(lastvalidIndex))
            {
                list.set(lastvalidIndex+1,list.get(i));
                lastvalidIndex++;
            }
            i++;
        }

        System.out.print("values:");
        for(i = 0;i<=lastvalidIndex;i++){
            System.out.printf("%d\t",list.get(i));
        }
        System.out.println();

    }

    public static void moveZerosToEnd(List<Integer> list){

        int j = 0;
        for(int i=0;i<list.size();i++){
            if(list.get(i)!=0){
                int temp = list.get(i);
                list.set(i,list.get(j));
                list.set(j,temp);
                j++;
            }
        }

        display(list);
    }

    public static void main(String[] args){
        
        List<Integer> list =  new ArrayList<>(List.of(1,2,3,4,5));
        
        findLargestAndSmallest(list);
        findSecondLargest(list);

        countEvenOrOdd(list);
        System.out.printf("Is Sorted:%b\n",checkSortedArray(list));

        reverseArray(list);
        display(list);

        System.out.printf("Is palimdrome:%b\n",isPlamindrome(new ArrayList<>(List.of(1,1,1,1))));

        countFrequency(list);

        System.out.printf("Missing Number:%d\n",findMissingNumber(list));

        removeDuplicate(new ArrayList<>(List.of(1,1,1,1,2,3)));

        moveZerosToEnd(list);
        return;
    }
}