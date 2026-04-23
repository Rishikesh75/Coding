
import java.util.Scanner;

public class Basics6 {
    
    public static void pattern1(int n){
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                System.out.print("*\t");
            }
            System.out.println();
        }

        return;
    }

    public static void pattern2(int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>=i;j--)
            {
                System.out.print("*\t");
            }
            System.out.println();
        }
    }

    public static void pattern3(int n)
    {
        int[] arr = new int[2];
        arr[0] = n;
        arr[1] = n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=2*n-1;j++)
            {
                if(j>=arr[0] && j<=arr[1])
                {
                    System.out.print("*");
                }
                else 
                {
                    System.out.print(" ");
                }
            }
                System.out.println();
                arr[0]--;
                arr[1]++;
        }

        return;
    }

    public static void pattern4(int n)
    {
        int sum = 1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                System.out.printf("%d\t",sum);
                sum++;
            }
            System.out.println();
        }

        return;
    }

    public static void pattern5(int n)
    {
        int[] arr = new int[2];
        arr[0] = n;
        arr[1] = n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=2*n-1;j++)
            {
                if(j>=arr[0] && j<=arr[1])
                {
                    System.out.print("*");
                }
                else 
                {
                    System.out.print(" ");
                }
            }
                System.out.println();
                arr[0]--;
                arr[1]++;
        }

        arr[0] = arr[0]+2;
        arr[1] = arr[1] - 2;


        int n1 = n-1;
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<=2*n-1;j++)
            {
                if(j>=arr[0] && j<=arr[1])
                {
                    System.out.print("*");
                }
                else 
                {
                    System.out.print(" ");
                }
            }
                System.out.println();
                arr[0]++;
                arr[1]--;
        }
        return;
    }
    public static void main(String[] args) {
        

        Scanner sc = new Scanner(System.in);

        var n = Integer.parseInt(sc.nextLine());

        pattern1(n);
        pattern2(n);
        pattern3(n);
        pattern4(n);
        pattern5(n);
    }
}
