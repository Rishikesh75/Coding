import java.util.*;
public class Basics1
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Helloo java");

        String  name;
        int age;
        String city;

        System.out.println("Enter Name Age city in java");
        name = sc.next();
        age = sc.nextInt();
        city = sc.next();
        System.out.printf("%s %d %s\n",name,age,city);

        int n = sc.nextInt();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                System.out.print("*");
            }
            System.out.println();
        }




    }
}