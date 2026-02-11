import java.util.*;
public class Basics2
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int i =1;
        long l = 12121231;

        float f = 1.1f;
        double d = 1.22;

        boolean b = true;

        char c = '1';
        String s = "djfals";

        System.out.printf("%d %d %f %f %b %c %s\n",i,l,f,d,b,c,s);

        int num1 = sc.nextInt();
        int num2 = sc.nextInt();

        System.out.printf("sum:%d sub:%d mul:%d div:%f",num1+num2,num1-num2,num1*num2,(double)num1/num2);

        double dInt = (double)i;
        System.out.printf("Integer value:%d Double Value:%f\n",i,dInt);

        System.out.printf("Before Swap:num1:%d num2:%d\n",num1,num2);

        num1 = num1-num2;
        num2 = num2+num1;
        num1 = num2 - num1;

        System.out.printf("After Swap:num1:%d num2:%d\n",num1,num2);

        int asciValue = (int)'c';
        System.out.printf("Ascivalue:%d",asciValue);
    }

}