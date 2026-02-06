//Perfix Sum Pattern
import java.util.*;
public class MyPair
{
    public Integer firstValue;
    public Integer secondValue;

    MyPair(int v1,int v2)
    {
        firstValue = v1;
        secondValue = v2;
    }
}
public class ArrayList3
{
    public static void displayPair(List<MyPair>ans)
    {
        for(var val : ans)
        {
            System.out.printf("%d %d",val.firstValue,val.secondValue);
        }
    }
    public static void displayInteger(List<Integer>ans)
    {
        for(var val : ans)
        {
            System.out.printf("%d\t",val);
        }
    }
    public static void  subarrayWithSumK(List<Integer>list,int k)
    {
        List<MyPair>ans = new ArrayList<>();
        Map<Integer,Integer>map = new HashMap<>();
        int i = 0,sum= 0;
        int n = list.size();
        while(i<n)
        {

            sum = sum + list.get(i);
            map.put(sum,i);
            if(map.containsKey(sum-k))
            {
                ans.add(new MyPair(map.get(sum-k)+1,i));
            }

            i++;

        }
        displayPair(ans);
    }
    public static void rangeQuery(List<Integer>list,List<MyPair>ques)
    {
        List<Integer>ans = new ArrayList<>();
        Map<Integer,Integer>map = new HashMap<>();
        int i=0,sum=0;

        while(i<list.size())
        {
            sum = sum + list.get(i);
            map.put(i,sum);
            i++;
        }

        for(var q : ques)
        {
            int prevSum = map.get(q.firstValue-1);
            int totalSum = map.get(q.secondValue);
            int currentSum = totalSum - prevSum;
            ans.add(currentSum);
        }

        displayInteger(ans);
    }

    public static void equlibriumIndex(List<Integer>list)
    {
        int i = 0,n = list.size(),sum = 0;
        List<Integer>ans = new ArrayList<>();
        while(i<n)
        {
            sum = sum + list.get(i);
            i++;
        }

        int leftSum = 0,rightSum = sum;
        i = 0;

        while(i<n)
        {
            rightSum = rightSum - list.get(i);
            if(leftSum == rightSum)
                ans.add(i);
            leftSum  = leftSum + list.get(i);
            i++;
        }

        displayInteger(ans);
    }

    public static void productOfSelf(List<Integer>list)
    {
        List<Integer>ans = new ArrayList<>(Collections.nCopies(list.size(),0));

        ans.set(0,1);

        for(int j=1;j<list.size();j++)
        {
            ans.set(j,ans.get(j-1)*list.get(j-1));
        }

        int value = list.get(list.size()-1);
        for(int j=list.size()-2;j>=0;j--)
        {
            ans.set(j,ans.get(j)*value);
            value = value * list.get(j);
        }

        displayInteger(ans);
    }

    public static boolean checkSubarrayWithSumZero(List<Integer>list)
    {
        int i = 0,sum = 0,n = list.size();
        Map<Integer,List<Integer>>map = new HashMap<>();
        map.put(0,new ArrayList<Integer>(Arrays.asList(0)));

        while(i<n)
        {
            sum = sum + list.get(i);

            if(map.containsKey(sum))
            {

                return true;
            }
            map.put(sum,new ArrayList<Integer>(Arrays.asList(i)));
            i++;
        }

        return false;
    }
    public static void main(String[] args)
    {
//        System.out.println("Hellooo Java...");
//        subarrayWithSumK(new ArrayList<Integer>(Arrays.asList(1,2,3,4)),5);
//        rangeQuery(new ArrayList<Integer>(Arrays.asList(1,2,3,4)),new ArrayList<MyPair>(Arrays.asList(new MyPair(1,2))));
//        equlibriumIndex(new ArrayList<Integer>(Arrays.asList(2,2,3,4)));
//          productOfSelf(new ArrayList<Integer>(Arrays.asList(2,2,2,3)));
        System.out.printf("%b",checkSubarrayWithSumZero(new ArrayList<Integer>(Arrays.asList(2,-2,3,-3))));
    }
}