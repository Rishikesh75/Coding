import java.util.*;
public class Basics5
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i=1;i<=n;i++)
        {
            System.out.printf("%d\t",i);
        }
        System.out.println();
        for(int i=1;i<=10;i++)
        {
            System.out.printf("%d * %d=%d\n",n,i,n*i);
        }
        int val = 1;
        for(int i=1;i<=n;i++)
        {
            val = val * i;
        }
        System.out.printf("factorial value:%d\n",val);

        int reversedNumber = 0;
        int orginalNumber = n;
        int countDigits = 0;
        int sumOfDigits = 0;
        while(n!=0)
        {
            int rem = n % 10;
            sumOfDigits = sumOfDigits + rem;
            n = n / 10;
            reversedNumber = reversedNumber * 10 + rem;
            countDigits++;
        }
        boolean isPlaimdrome = reversedNumber == orginalNumber ? true : false;
        System.out.printf("Orginal Number :%d Reversed Number:%d palimdrome:%b No of Digits:%d Sum of Digits:%d\n",orginalNumber,reversedNumber,isPlaimdrome,countDigits,sumOfDigits);

        int prev = 0;
        int curr = 1;
        if(n == 1) System.out.printf("0\t");
        if(n == 2) System.out.printf("1\t");
        else
        {
            System.out.printf("0\t");
            System.out.printf("1\t");
            for(int i=3;i<=orginalNumber;i++)
            {
                int currentval = prev + curr;
                prev = curr;
                curr = currentval;
                System.out.printf("%d\t",currentval);
            }
        }
        System.out.println();
        boolean isPrime = true;
        int count = 1;

        for(int i=2;i<orginalNumber;i++)
        {
            if(orginalNumber % i == 0) count++;
            if(count >=2) isPrime = false;
        }
        System.out.printf("isPrime:%b",isPrime);

    }
}