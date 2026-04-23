import java.util.Scanner;

public class Basics1 {
    
    public static void main(String[] args) {
        System.out.println("Helloo World");

        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the name: ");
        String name = sc.nextLine();

        System.out.print("Enter the age: ");
        int age = Integer.parseInt(sc.nextLine());
        

        System.out.print("Enter the city: ");
        String city = sc.nextLine();

        System.out.printf("Name: %s Age: %d City: %s\n", name, age, city);



        System.out.print("Enter the n:");
        int n = Integer.parseInt(sc.nextLine());

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                System.out.print("*\t");
            }
            System.out.println();
        }
    }

}