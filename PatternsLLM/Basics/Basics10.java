import java.util.*;
public class Basics10
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        int val = n;
        for(int i=n-1;i>=1;i--)
        {
            val=val * i;
        }
        System.out.printf("Factorial Value: %d",val);
    }
}