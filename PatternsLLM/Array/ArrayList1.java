import java.util.*;
public class ArrayList1
{
    public static Scanner sc = new Scanner(System.in);
    public static List<Integer> createArr(int n)
    {
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter the number:");
            int temp = sc.nextInt();
            list.add(temp);
        }
        return list;
    }
    public static void display(List<Integer> list)
    {
        System.out.print("Arr:");
        for(var element : list)
        {
            System.out.printf("%d\t",element);
        }
        System.out.println();
        return;
    }
    public static int findMax(List<Integer>list)
    {
        int val = Integer.MIN_VALUE;
        for(var num : list)
        {
            val = Integer.max(val,num);
        }
        return val;
    }
    public static int findMin(List<Integer>list)
    {
        int val = Integer.MAX_VALUE;
        for(int i=0;i<list.size();i++)
        {
            val = Integer.min(list.get(i),val);
        }
        return val;
    }
    public static int findSum(List<Integer>list)
    {
        int val = 0;
        var iterator = list.iterator();
        while(iterator.hasNext())
        {
            val = val + iterator.next();
        }
        return val;
    }
    public static List<Integer> findEvenAndOddCount(List<Integer>arr)
    {
        List<Integer>ans = new ArrayList<>();
        Integer evenCount = 0;
        Integer oddCount = 0;
        for(var num : arr)
        {
                if(num%2 == 0)
                {
                    evenCount += 1;
                }
                else
                {
                    oddCount += 1;
                }
        }
        ans.add(evenCount);
        ans.add(oddCount);
        return ans;
    }
    public static void reverseArray(List<Integer>arr)
    {
        int i = 0;
        int j = arr.size()-1;
        while(i<j)
        {
            int v = arr.get(i);
            arr.set(i,arr.get(j));
            arr.set(j,v);
            i = i+1;
            j = j-1;
        }
        display(arr);
    }
    public static int findSecondLargest(List<Integer>list)
    {
        int firstLargest = list.get(0) > list.get(1) ? list.get(0) : list.get(1);
        int secondLargest  = firstLargest == list.get(0) ? list.get(1) : list.get(0);
        for(int i=2;i<list.size();i++)
        {
            if(list.get(i)>firstLargest)
            {
                secondLargest = firstLargest;
                firstLargest = list.get(i);
            }
            else if(list.get(i)>secondLargest)
            {
                secondLargest = list.get(i);
            }
        }
        return secondLargest;
    }
    public static boolean checkSorted(List<Integer>list)
    {
        for(int i=1;i<list.size();i++)
        {
            if(list.get(i)>list.get(i-1))
            {
                return false;
            }
        }
        return true;
    }

    public static boolean linearSearch(List<Integer>list,int val)
    {
        for(var num : list)
        {
            if(num == val) return true;
        }
        return false;
    }
    public static List<Integer> removeDuplicates(List<Integer> list) {
        Set<Integer> set = new LinkedHashSet<>();
        for (int num : list) {
            set.add(num);
        }
        return new ArrayList<>(set);
    }
    public static void main(String[] args)
    {


        Integer n;
        System.out.println("Enter the Size of the ArrayList:");
        n = sc.nextInt();

        List<Integer> list = createArr(n);
        display(list);
        System.out.printf("Max Value:%d\n",findMax(list));
        System.out.printf("Min Value: %d\n",findMin(list));
        System.out.printf("Sum value:%d\n",findSum(list));

        var ans = findEvenAndOddCount(list);
        System.out.printf("even count :%d odd count :%d\n",ans.get(0),ans.get(1));

        reverseArray(list);

        System.out.printf("SecondLargest Element: %d\n",findSecondLargest(list));

        System.out.printf("Check Sorted%b\n",checkSorted(list));

        System.out.printf("Element Found %b\n",linearSearch(list,1));
    }
}