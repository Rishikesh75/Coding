import java.lang.*;
public class Basics5 {
    
    public static void print1to100()
    {
        for(int i=0;i<100;i++)
        {
            System.out.printf("%d\t",i);
        }
        System.out.println();
    }

    public static void print100to1()
    {
        for(int i=100;i>=0;i--)
        {
            System.out.printf("%d\t",i);
        }

        return;
    }

    public static int sum(int n)
    {
        int sum = 0;
        for(int i=1;i<=n;i++)
        {   
            sum += i;
        }
        return sum;
    }

    public static void Mutiply(int n)
    {
        for(int i=1;i<=10;i++)
        {
            System.out.printf("%d*%d:{%d}\n",n,i,n*i);
        }

        return;
    }

    public static int findFactorial(int n)
    {
        int val = 1;

        for(int i=1;i<n;i++)
        {
            val *= i;
        }

        return val;
    }

    public static int reverseNumber(int n)
    {
        int val = 0;

        while(n != 0)
        {
            int rem = n % 10;
            val = val * 10 + rem;

            n = n / 10;
        }

        return val;
    }

    public static boolean  isPlaimdrome(int val)
    {
        String valstr = Integer.toString(val);

        StringBuilder sb = new StringBuilder(valstr);
        
        int i = 0;
        int j = sb.length()-1;

        while(i<j)
        {
            if(sb.charAt(i) != sb.charAt(j))
                return  false;

            i++;
            j--;
        }

        return true;
    }

    public static int countDigits(int n)
    {
        int count = 0;

        while(n!=0)
        {
            count++;
            n = n / 10;
        }

        return count;
    }

    public static int sumOfDigits(int n)
    {
        int sumOfDigits = 0;

        while(n!=0)
        {
            int rem = n % 10;
            sumOfDigits += rem;
            n = n / 10;
        }

        return sumOfDigits;
    }

    public static void printFib(int n)
    {
        int num1= 0;
        int num2 = 1;

        int val = 0;

        while(val<n)
        {
            if(val == 0)
            {
                System.out.printf("%d\t",num1);
                val++;
                continue;
            }
                
            if(val == 1)
            {
                System.out.printf("%d\t",num2);
                val++;
                continue;
            }

            int tempVal = num1 + num2;
            System.out.printf("%d\t",tempVal);
            num1 = num2;
            num2 = tempVal;
            val++;
        }

        System.out.println();
        return;
    }

    public static boolean isPrime(int n)
    {
        for(int i=2;i<n;i++)
        {
            if(n%i == 0)
                return false;
        }

        return true;
    }
    public static void main(String[] args) {
        // print100to1();

        // print100to1();

        // sum(100);

        // Mutiply(100);

        // isPlaimdrome(101);

        printFib(20);

        isPrime(5);

    }
}
