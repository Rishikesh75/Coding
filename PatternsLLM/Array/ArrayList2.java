import java.util.*;
public class ArrayList2
{
    public static Scanner sc = new Scanner(System.in);
    public static int maxSum(List<Integer>list,int k)
    {
        int start = 0;
        int end = k - 1;
        int currentSum = 0;
        int maxSum = Integer.MIN_VALUE;
        for(int i=0;i<=end;i++)
        {
            currentSum = currentSum + list.get(i);
            maxSum = Math.max(maxSum,currentSum);
        }
        while(end < list.size()-1)
        {
            currentSum = currentSum - list.get(start) + list.get(end+1);
            maxSum = Math.max(maxSum,currentSum);
            start = start + 1;
            end = end + 1;
        }
        return maxSum;
    }

    public static int longestSubArray(List<Integer>list)
    {
        int val;
        val = sc.nextInt();
        int start = 0;
        int end = 0;
        int sum = list.get(0);
        int currentlen = 1;
        int maxlen = Integer.MIN_VALUE;
        while(end<list.size())
        {
            if(sum < val)
            {
                end = end + 1;
                currentlen = currentlen + 1;
                sum = sum + list.get(end);
            }
            else if(sum >=val)
            {
                maxlen = Math.max(maxlen,currentlen);
                start = start + 1;
                currentlen = currentlen - 1;
            }
        }
        return maxlen;
    }

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
    
    public static void main(String[] args)
    {
        List<Integer> list = new ArrayList<>();
        CreateArr(list);
        // int k;
        // k = sc.nextInt();
        // System.out.printf("Maxsum:%d",maxSum(list,k));
        System.out.printf("len:%d",longestSubArray(list));
    }

}