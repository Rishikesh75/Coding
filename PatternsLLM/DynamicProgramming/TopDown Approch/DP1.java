import java.util.*;
public class DP1
{

    public static List<Integer> dp;
    public static int fib(int n)
    {
        if(n == 0) return dp.get(0);

        if(n == 1) return dp.get(1);

        if(dp.get(n-1) == 0) dp.set(n-1 , fib(n-1));

        if(dp.get(n-2) == 0) dp.set(n-2, fib(n-2)) ;

        return dp.get(n-1) + dp.get(n-2);
    }

    public static void main(String[] args)
    {

        int value = 5;

        dp = new ArrayList<Integer>(Collections.nCopies(value+1,0));
        dp.set(0,0);
        dp.set(1,1);
        System.out.printf("Ans:%d",fib(value));

    }

}