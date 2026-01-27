import java.util.*;
public class Basics11
{
    public static void main(String[] args)
    {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int val_1 = 1;
        int val_2 = 1;
        for(int i=1;i<=n;i++)
        {
            if(i == 1)
                System.out.printf("%d",1);
            else if(i == 2)
                System.out.printf("%d",1);
            else
            {
                int temp = val_1;
                val_1=val_1+val_2;
                val_2 = temp;
                System.out.printf("%d",val_1);
            }

        }
    }
}