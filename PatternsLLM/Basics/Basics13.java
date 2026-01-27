import java.util.*;
public class Basics13
{
    public static int digitsCount(int number)
    {
        int count =0;
        while(true)
        {
            if(number == 0)
            {
                break;
            }
            int rem = number % 10;
            count = count + 1;
            number = number / 10;
        }
        return count;
    }
    public static  void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        int cpynumber = number;
        int countDigits = digitsCount(number);
        int sum = 0;

        while(number!=0)
        {
            int rem = number %10;
            sum += Math.pow(rem,countDigits);
            number = number / 10;
        }
        if(cpynumber == sum) System.out.println("Yes");
        else System.out.println("No");
        return;
    }
}