package Patterns;
import java.text.ListFormat.Style;
import java.util.Scanner;
public class Patterns
{
    
    static void  pattern_1(int n)
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
    static void pattern_2(int n)
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
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the No of Rows");
        int n = sc.nextInt();
        //pattern_1(n);
        pattern_2(n);
        sc.close();
    }
}