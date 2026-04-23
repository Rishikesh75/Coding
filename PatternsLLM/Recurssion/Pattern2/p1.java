
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class p1 {
    
    public static List<List<Integer>> combinations = new ArrayList<>();


    public static List<Integer> arr = new ArrayList<>(List.of(1,2,3));

    public static List<Boolean> hashArr = new ArrayList<>(Collections.nCopies(arr.size(),false));
    
    public static void allCombinations(int currIndex,List<Boolean> hashArr,List<Integer> ans)
    {
        if(currIndex == arr.size()){
            combinations.add(new ArrayList<>(ans));
            return;
        }

        for(int i = 0;i<arr.size();i++){
            
            if(!hashArr.get(i)){
                //Include
                hashArr.set(i,true);
                ans.add(arr.get(i));
                
                allCombinations(currIndex+1, hashArr,ans);
                
                //BackTracking
                hashArr.set(i,false);
                ans.remove(arr.get(i));
            }

        }
    }

    //Method-2

    public static void displayCombinations()
    {
        for(var combination : combinations){
            System.out.print("combinations:");
            for(var val : combination){
               System.out.printf("%d\t",val); 
            }
            System.out.println();
        }
    }


    public static void main(String[] args){

        allCombinations(0, hashArr, new ArrayList<>());
        displayCombinations();
        return;
    }
}
