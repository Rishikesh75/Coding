import java.util.*;
public class Basics12
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n,m;
        n = sc.nextInt();
        m = sc.nextInt();
        int pr = m*n;
        int val;
        while(true)
        {
            int rem = n % m;
            if(rem == 0)
            {
                val = m;
                break;
            }
            m = rem;
            n = m;
        }

        System.out.printf("GCD:%d",val);
        System.out.printf("LCM:%d",(pr)/val);
    }
}