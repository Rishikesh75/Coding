import java.util.*;
public class Basics
{
    public static void main(String[] args)
    {
        int m,n;
        Scanner sc = new Scanner(System.in);
        m = sc.nextInt();
        n = sc.nextInt();
        if(m>n)
        {
            System.out.println("First Number is Greather than the second Number");
        }
        else if(m<n)
        {
            System.out.println("Secong Number is Greather than the First Number");
        }
        else
        {
            System.out.println("First Number and Second Number are Eqaul");
        }
    }

}