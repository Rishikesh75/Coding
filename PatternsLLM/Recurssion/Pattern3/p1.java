
import java.util.ArrayList;
import java.util.List;

public class p1
{
    public static List<Integer> list = new ArrayList<>(List.of(1,2,3,4,5));

    public static void display()
    {
        System.out.print("Array:");
        for(var val : list){
            System.out.printf("%d",val);
        }
        System.out.println();
    }

    public static boolean binarySearch(int startIndex,int endIndex,int val)
    {
        if(startIndex > endIndex) 
            return false;
        
        int midIndex = startIndex + (endIndex - startIndex) /2;

        if(list.get(midIndex) == val)
            return true;

        if(list.get(midIndex) > val)
            return binarySearch(startIndex,midIndex-1, val);

        else 
            return binarySearch(midIndex+1, endIndex, val);
    }

    public static void main(String[] args) {
        
        display();

        System.out.printf("Binary Search:%b",binarySearch(0, list.size()-1, 3));
        return;
    }
}