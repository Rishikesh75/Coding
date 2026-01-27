import java.util.*;
public class Basics9
{
    public static boolean checkPrime(int num)
    {
        int count =0;
        if(num == 1)
        {
            return false;
        }
        for(int i=2;i<num;i++)
        {
            if(num % i == 0) count++;
        }

        return count == 0 ? true : false;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        for(int i=1;i<=n;i++)
        {
            if(checkPrime(i))
            {
                System.out.printf("%d is the prime Number..\n",i);
            }
        }
    }
}