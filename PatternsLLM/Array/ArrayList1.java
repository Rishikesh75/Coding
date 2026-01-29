
import java.util.*;
public class Main
{
    public static Scanner sc = new Scanner(System.in);
    public static void CreateArr(List<Integer>list)
    {
        System.out.println("Enter the size of the Arr:");
        int n = sc.nextInt();
        // list.resize(n);
        for(int i=0;i<n;i++)
        {
            int number = sc.nextInt();
            list.add(number);
        }
    }
    public static void display(List<Integer>list)
    {
        for(var num : list)
        {
            System.out.printf("%d\t",num);
        }
        System.out.println();
    }
    public static int findLargest(List<Integer>list)
    {
        int val = Integer.MIN_VALUE;
        for(int i=0;i<list.size();i++)
        {
            val = Math.max(val,list.get(i));
        }
        return val;
    }
    public static int findSecondLargest(List<Integer>list)
    {
        int firstMax = list.get(0);
        int secondMax = Integer.MIN_VALUE;
        for(int i=1;i<list.size();i++)
        {
            if(list.get(i) > firstMax)
            {
                secondMax = firstMax;
                firstMax = list.get(i);
            }
            else if(list.get(i) > secondMax)
            {
                secondMax = list.get(i);
            }
        }
        return secondMax;
    }
    public static boolean checkArraySorted(List<Integer>list)
    {
        for(int i=1;i<list.size();i++)
        {
            if(list.get(i)<list.get(i-1))
            {
                return false;
            }
        }
        return true;
    }
    public static Mypair countEvenOdd(List<Integer>list)
    {
        Mypair pair = new Mypair();
        for(int i=0;i<list.size();i++)
        {
            if(list.get(i)%2 == 0)
            {   
                pair.evenNumberCount += 1;
            }
            else 
            {
                pair.oddNumberCount += 1;
            }
        }
        return pair;
    }
    public static void reverseArray(List<Integer>list)
    {
        int start = 0;
        int end = list.size()-1;
        while(start<end)
        {
            int temp = list.get(start);
            list.set(start,list.get(end));
            list.set(end,temp);
            start=start+1;
            end=end-1;
        }
        
    }
    public static void removeDuplicate(List<Integer>list)
    {
        Set<Integer>set = new HashSet<>(list);
        
        Iterator<Integer> it = set.iterator();
        while(it.hasNext())
        {
            Integer val = it.next();
            System.out.printf("%d\t",val);
            it.remove();
        }
        System.out.printf("size:%d",set.size());
    }
    public static boolean isPalindrome(List<Integer>list)
    {
        int i = 0;
        int j = list.size()-1;
        while(i<j)
        {
            if(list.get(i) != list.get(j))
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    public static int missingNumber(List<Integer>list)
    {
        int val = 0;
        for(int i=0;i<list.size();i++)
        {
            val = val ^ list.get(i) ^ i;
        }
        val = val ^ list.size();
        return val;
    }
    public static void moveZerosEnd(List<Integer>list)
    {
        int start = 0;
        int end = list.size()-1;
        while(start<end)
        {
            if(list.get(start) != 0)
            {
                start = start + 1;
                continue;
            }
            if(list.get(end) == 0)
            {
                end = end - 1;
                continue;
            }
            
            int temp = list.get(start);
            list.set(start,list.get(end));
            list.set(end,temp);
            start = start + 1;
            end = end - 1;
        }
    }
    public static void frequencyCount(List<Integer>list)
    {
        Map<Integer,Integer>map = new HashMap<>();
        for(int num :list)
        {
            if(map.containsKey(num))
            {
                map.replace(num,map.get(num)+1);
                continue;
            }
            map.put(num,1);
        }
        
        for(Map.Entry<Integer,Integer> item : map.entrySet())
        {
            System.out.printf("%d %d",item.getKey(),item.getValue());
        }
    }
    public static void main(String[] args)
    {
        List<Integer> list = new ArrayList<>();
        CreateArr(list);
        // display(list);
        // System.out.printf("Max Value:%d\n",findLargest(list));
        // System.out.printf("Second Max Value:%d\n",findSecondLargest(list));
        // System.out.printf("Sorted Array: %b\n",checkArraySorted(list));
        // var ans = countEvenOdd(list);
        // System.out.printf("Even Count Number:%d Odd Count Number:%d",ans.evenNumberCount,ans.oddNumberCount);
        // reverseArray(list);
        // System.out.println("Reversed Array:\n");
        // display(list);
        // System.out.println("Remove Duplicates Array:\n");
        // removeDuplicate(list);
        // System.out.printf("isPalindrome:%b",isPalindrome(list));
        // System.out.printf("%d",missingNumber(list));
        // moveZerosEnd(list);
        // display(list);
        // frequencyCount(list);
        
    }
    
    public static class Mypair
    {
        Integer evenNumberCount;
        Integer oddNumberCount;
        
        Mypair()
        {
            this.evenNumberCount = 0;
            this.oddNumberCount = 0;
        }
    }
}