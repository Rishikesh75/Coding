
import java.util.ArrayList;
import java.util.List;

public class p2 {
    
    public static List<Integer> list = new ArrayList<>(List.of(1,2,5,4,5,6));

    public static void display(){

        System.out.printf("Display:\t");

        for(var val: list){
            System.out.printf("%d\t",val);
        }

        System.out.println();
        return;
    }

    
    public static void mergeList(int startIndex,int midIndex,int endIndex)
    {
        List<Integer> tempList = new ArrayList<Integer>();

        int i1 = startIndex;
        int i2 = midIndex+1;
        
        while(i1<=midIndex && i2<=endIndex){
            
            if(list.get(i1)>list.get(i2)){
                tempList.add(list.get(i2));
                i2++;
            }

            else{
                tempList.add(list.get(i1));
                i1++;
            }

        }

        while(i1<=midIndex){
            tempList.add(list.get(i1));
            i1++;
        }

        while(i2<=endIndex){
            tempList.add(list.get(i2));
            i2++;
        }

        for(int k=0;k<tempList.size();k++){
            list.set(startIndex + k, tempList.get(k));
        }

        return;
    }
    public static void mergeSort(int startIndex,int endIndex)
    {
        if(startIndex >= endIndex)
            return;

        int midIndex = startIndex + (endIndex - startIndex)/2;

        mergeSort(startIndex, midIndex);
        mergeSort(midIndex+1, endIndex);

        mergeList(startIndex,midIndex,endIndex);
        return;
    }


    public static void main(String[] args) {
        
        mergeSort(0,list.size()-1);
        display();
        return;
    }
}
