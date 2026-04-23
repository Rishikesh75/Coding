
import java.util.Scanner;

public class P1 {
    

    //print 1 to N
    public static void print1toN(int n){

        if(n == 0) return;
        
        System.out.printf("%d",n);

        print1toN(n-1);

        return;
    }

    public static int factorial(int n)
    {
        if(n == 1)
            return 0;

        if(n == 2)
            return 1;

        return factorial(n-1) + factorial(n-2);
    }

    public static int sum(int n){

        if(n == 0)
            return 0;

        return n+sum(n-1);
    }

    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        System.out.printf("Numbers:");
        print1toN(n);
        System.out.println();

        System.out.printf("Factorial:%d\n",factorial(n));
        System.out.printf("Sum:%d\n",sum(n));
    }
}
