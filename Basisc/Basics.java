import java.util.*;
public class Basics
{

    public static void HelloWorld()
    {
        System.out.println("Hello World");
    }
    public static void main(String[] args)
    {
        System.out.println("HelloWorld");
        Scanner sc = new Scanner(System.in);
        int val = sc.nextInt();
        switch(val%2)
        {
            case 0:
                System.out.println("EVEN NUMBER");
                break;
            case 1:
                System.out.println("ODD NUMBER");
                break;
        }
        for(int i=0;i<3;i++)
        {
            System.out.println("Rishi");
        }
        HelloWorld();
    }
}