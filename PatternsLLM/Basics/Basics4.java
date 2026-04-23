import java.util.Scanner;

public class Basics4 {
    public static double cal(int a,int b,char c)
    {
        double v;
        switch (c) {
            case '+':
                {
                    v = (double)a + b;
                    break;
                }
            case '-':
                {
                    v = (double) a - b;
                    break;
                }
            case '*':
                {
                    v = (double) a * b;
                    break;
                }
            case '/':
                {
                    v = (double) a /b;
                    break;
                }
            default:
                throw new AssertionError();
        }

        return v;
    }

    public static boolean isVowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o'  || c == 'u')
            return true;
        
        return  false;
    }

    public static char Marks(int marks)
    {
        if(marks > 90)
            return 'A';
        else if(marks > 80)
            return 'B';
        else
            return 'C';
    }
    public static  void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        cal(1, 2, '+');

        System.out.printf("isVowel:%b",isVowel(sc.nextLine().charAt(0)));
        return;
    }
}
