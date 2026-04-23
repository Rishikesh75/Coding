
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
class Count{
    public int even;
    public int odd;

    public Count(int even,int odd)
    {
        this.even = even;
        this.odd = odd;
    }
}
public class Array1
{
    
    public static List<Integer> list = IntStream.range(0, 5)
                        .mapToObj(i -> i)
                        .collect(Collectors.toList());;

    
    public static int findLargestElement()
    {

        int largestElement = Integer.MIN_VALUE;

        for(int val : list)
        {
            largestElement = Math.max(val, largestElement);
        }

        return largestElement;
    }

    public static int findSecondLargest()
    {

        int firstLargestElement = list.get(0);
        int seconLargestElement = Integer.MIN_VALUE;

        for(int i=1;i<list.size();i++)
        {
            int currVal = list.get(i);

            if(currVal > firstLargestElement){
                
                seconLargestElement = firstLargestElement;
                firstLargestElement = currVal;
            }
            else if(currVal > seconLargestElement)
            {
                seconLargestElement = currVal;
            }
        }

        return  seconLargestElement;
    }

    public static boolean isSorted()
    {
        for(int i=1;i<list.size();i++){
            if(list.get(i-1) > list.get(i))
                return  false;
        }

        return true;
    }

    public static Count countEvenOdd()
    {
        Count count = new Count(0, 0);

        for(var ele : list){
            if(ele % 2 == 0)
                count.even++;
            else 
                count.odd++;
        }

        return count;
    }

    public static void reverseArr()
    {
        int startIndx = 0;
        int endIndx = list.size()-1;

        while(startIndx < endIndx){

            int temp = list.get(startIndx);
            list.set(startIndx, list.get(endIndx));
            list.set(endIndx,temp);

            startIndx++;
            endIndx--;
        }

        return;
    }

    public static void display()
    {
        System.out.println();
        System.out.printf("Arr:\t");

        for(var val : list){
            System.out.printf("%d\t",val);
        }

        System.out.println();
    }

    public static boolean isPlamindrome()
    {
        int startIndx = 0;
        int lastIndx = list.size()-1;

        while(startIndx < lastIndx)
        {
            if(list.get(startIndx)!=list.get(lastIndx))
            {
                return false;
            }

            startIndx++;
            lastIndx--;
        }

        return true;
    }

    public static int findMissingNumber()
    {
        int n = list.size();

        int sum = 0;
        for(var val : list){
            sum += val;
        }

        return ((n * n -1)/2) - sum;

    }
    
    //Remove Duplicates from the sorted Array..


    //Move All the Zeros to the end..
    public static void main(String[] args) {
        
        System.out.printf("Maxvalue:%d\n",findLargestElement());
        System.out.printf("SecondLargestValue:%d\n",findSecondLargest());
        System.out.printf("Incresing Order:%b\n",isSorted());

        Count countEO = countEvenOdd();
        System.out.printf("Even count:%d\t Odd count:%d",countEO.even,countEO.odd);

        reverseArr();
        display();
    }
}