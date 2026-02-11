import java.util.*;
public class Basics3
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        if(n%2 == 0)
            System.out.println("Even Number");
        else
            System.out.println("Odd Number");

        int num1 = sc.nextInt();
        int num2 = sc.nextInt();

        if(num1>num2)
            System.out.println("Num1 is greather than Num2");
        if(num1<num2)
            System.out.println("Num2 is greather than Num1");

        int num3  = sc.nextInt();

        if(num3>num2)
        {
            if(num3>num1) System.out.println("Num3 is greathest");
            else System.out.println("Num1 is greathest");
        }
        else
        {
            if(num2>num1) System.out.println("num2 is greatest");
            else System.out.println("Num1 is greathest");
        }

        int number = sc.nextInt();

        if(number>0)
            System.out.println("Number is positive..");
        else if(number<0)
            System.out.println("Number is negative...");

        int leapYear = sc.nextInt();

        if(leapYear % 400 == 0 || leapYear % 100 != 0 &&  leapYear %4 == 0)
        {
                    System.out.println("Not Leap Year");
        }
        else
            System.out.println("Not Leap year");
    }
}