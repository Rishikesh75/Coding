
import java.util.Scanner;

public class Basics3 {
    
    public static boolean isEven(int a)
    {
        return a % 2 == 0;
    }

    public static int largestNumber(int a,int b)
    {
        if(a>b)
            return a;

        return b;
    }

    public static int largestNumber(int a,int b,int c)
    {
        if(a>b)
        {
            if(a>c)
                return a;
        }
        else 
        {
            if(b>c)
                return b;
        }

        return  c;
            
    }

    public static char findPosAndNegative(int a)
    {
        if(a>0)
            return 'P';
        if(a == 0)
            return '0';
        else
            return 'N';
    }

    public static boolean isLeapYear(int n)
    {
        if(n % 4 == 0)
        {
            if(n%100 == 0 && n % 400 !=0)
                return  false;

            else
                return true;
        }

        return false;
    }
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        // System.out.printf("%b\n",isEven(Integer.parseInt(sc.nextLine())));
        // System.out.printf("%d\n",largestNumber(Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine())));
        // System.out.printf("%d\n",largestNumber(Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine())));
        System.out.printf("Is Leap Year:%b\n",isLeapYear(Integer.parseInt(sc.nextLine())));
        return;
    }
}
