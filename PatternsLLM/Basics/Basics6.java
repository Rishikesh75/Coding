import java.util.*;
public class Basics6
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();


        for(int i=1;i<=n;i++) {
            for(int j=1;j<=i;j++) {
                System.out.print("*");
            }
            System.out.println();
        }

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n-i+1;j++) {
                System.out.print("*");
            }
            System.out.println();
        }

        int startRow = n;
        int endRow = n;
        for(int i=1;i<=n;i++) {
            for(int j = 1;j<=2*n-1;j++) {
                    if(j>=startRow && j<=endRow) System.out.print("*");
                    else System.out.print(" ");
            }
            System.out.println();
            startRow--;
            endRow++;
        }

         startRow = 1;
         endRow = 2*n-1;
        for(int i=1;i<=n;i++) {
            for(int j = 1;j<=2*n-1;j++) {
                if(j>=startRow && j<=endRow) System.out.print("*");
                else System.out.print(" ");
            }
            System.out.println();
            ++startRow;
            --endRow;
        }
        int val = 1;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=i;j++) {
                System.out.printf("%d",val);
                val++;
            }
            System.out.println();
        }
    }
}