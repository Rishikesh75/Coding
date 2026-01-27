import java.util.*;
public class Basics5
{
    public static void main(String[] args)
    {
        int n;
        System.out.println("Enter the Number:");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for(int i=1;i<=n;i++)
        {
            System.out.printf("%d\t",i);
        }
    }
}