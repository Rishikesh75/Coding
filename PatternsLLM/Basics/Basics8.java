import java.util.*;

public class Basics8 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int original = n;
        int reversed = 0;

        while (n != 0) {
            int rem = n % 10;
            reversed = reversed * 10 + rem;
            n = n / 10;
        }

        if (original == reversed) {
            System.out.println("It is a Palindrome");
        } else {
            System.out.println("It is not a Palindrome");
        }
    }
}
