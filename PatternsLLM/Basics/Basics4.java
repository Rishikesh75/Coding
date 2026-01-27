import java.util.*;
public class Basics4
{
    public static void main(String[] args)
    {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int num = 0;
        for(int i = 1;i<=n;i++)
        {
            num = num + i;
        }
        System.out.printf("Sum is :%d",num);
    }
}