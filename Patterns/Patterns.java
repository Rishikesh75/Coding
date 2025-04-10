
import java.util.Scanner;
public class Patterns
{
    
    public static void  pattern_1(int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j =1;j<=n;j++)
            {
                System.out.print("*\t");
            }
                System.out.print("\n");
        }
    }
    public static void pattern_2(int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                System.out.print("*\t");
            }
            System.out.print("\n");
        }
    }
    public static void pattern_3(int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                System.out.printf("%d \t",j);
            }
            System.out.print("\n");
        }
    }
    public static void pattern_4(int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                System.out.printf("%d \t",i);
            }
            System.out.print("\n");
        }
    }
    public static void pattern_5(int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=n-i+1;j>=1;j--)
            {
                System.out.print("*\t");
            }
            System.out.print("\n");
        }
    }
    public static void pattern_6(int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=n-i+1;j>=1;j--)
            {
                System.out.printf("%d\t",n-j+1);
            }
            System.out.print("\n");
        }
    }
    public static  void  pattern_7(int n)
    {
        int[] endpoints = new int[2];
        endpoints[0] = n;
        endpoints[1] = n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2*n-1;j++)
            {
                if( j>=endpoints[0] && j<=endpoints[1])
                {
                    System.out.printf("*\t");
                }
                else
                {
                    System.out.printf("\t");
                }
            }
            endpoints[0] = endpoints[0] -1 ;
            endpoints[1] =endpoints[1] + 1;
            System.out.print("\n");
        }
    }
    public static void pattern_8(int n)
    {
        int[] arr = new int[2];
        arr[0] = 1;
        arr[1] = 2*n-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2*n-1;j++)
            {
                if(j>=arr[0] && j<=arr[1])
                {
                    System.out.print("*\t");
                }
                else
                {
                    System.out.print(" \t");
                }
            }
            arr[0] = arr[0] + 1;
            arr[1] =arr[1] - 1;
            System.out.print("\n");
        }
    }
    public static void pattern_9(int n)
    {
        pattern_7(n/2);
        pattern_8(n/2);
    }
    public static void pattern_10(int n)
    {
        pattern_2(n/2+1);
        pattern_5(n/2);
    }
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter the No of Rows");
            int n = sc.nextInt();
            //pattern_1(n);
            //pattern_2(n);
            //pattern_3(n);
            //pattern_4(n);
            //pattern_5(n);
            //pattern_6(n);
            //pattern_7(n);
            //pattern_8(n);
            //pattern_9(n);
            pattern_10(n);
        }
    }
}