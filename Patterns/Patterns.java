
import java.util.Scanner;
public class Patterns
{
    
    public static void  pattern_1(int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j =1;j<=n;j++)
            {
                System.out.print("*\t");
            }
                System.out.print("\n");
        }
    }
    public static void pattern_2(int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                System.out.print("*\t");
            }
            System.out.print("\n");
        }
    }
    public static void pattern_3(int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                System.out.printf("%d \t",j);
            }
            System.out.print("\n");
        }
    }
    public static void pattern_4(int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                System.out.printf("%d \t",i);
            }
            System.out.print("\n");
        }
    }
    public static void pattern_5(int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=n-i+1;j>=1;j--)
            {
                System.out.print("*\t");
            }
            System.out.print("\n");
        }
    }
    public static void pattern_6(int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=n-i+1;j>=1;j--)
            {
                System.out.printf("%d\t",n-j+1);
            }
            System.out.print("\n");
        }
    }
    public static  void  pattern_7(int n)
    {
        int[] endpoints = new int[2];
        endpoints[0] = n;
        endpoints[1] = n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2*n-1;j++)
            {
                if( j>=endpoints[0] && j<=endpoints[1])
                {
                    System.out.printf("*\t");
                }
                else
                {
                    System.out.printf("\t");
                }
            }
            endpoints[0] = endpoints[0] -1 ;
            endpoints[1] =endpoints[1] + 1;
            System.out.print("\n");
        }
    }
    public static void pattern_8(int n)
    {
        int[] arr = new int[2];
        arr[0] = 1;
        arr[1] = 2*n-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2*n-1;j++)
            {
                if(j>=arr[0] && j<=arr[1])
                {
                    System.out.print("*\t");
                }
                else
                {
                    System.out.print(" \t");
                }
            }
            arr[0] = arr[0] + 1;
            arr[1] =arr[1] - 1;
            System.out.print("\n");
        }
    }
    public static void pattern_9(int n)
    {
        pattern_7(n/2);
        pattern_8(n/2);
    }
    public static void pattern_10(int n)
    {
        pattern_2(n/2+1);
        pattern_5(n/2);
    }
    public static void pattern_11(int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                if(j%2 == 1)
                {
                    System.out.print("1\t");
                }
                else
                {
                    System.out.print("0\t");
                }
            }
            System.out.print("\n");
        }
    }
    public static void pattern_12(int n)
    {
        int arr[] = new int[2];
        arr[0] = 2;
        arr[1] = 2*n-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2*n;j++)
            {
                if(j>=arr[0] && j<=arr[1])
                {   
                    
                    System.out.print(" \t");
                }
                else
                {
                    if(j>n)
                    {
                        System.out.printf("%d\t",n-(j-n)+ 1);
                    }
                    else
                    {
                        System.out.printf("%d\t",j);
                    }
                   
                }
            }
            System.out.print("\n");
            arr[0] = arr[0] + 1;
            arr[1] = arr[1] - 1;
        }
    }
    public static void pattern_13(int n)
    {
        int count =1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                System.out.printf("%d \t",count);
                count = count +1 ;
            }
            System.out.print("\n");
        }
    }
    
    public static void pattern_14(int n)
    {
       
        for(int i=1;i<=n;i++)
        {
            int c = 'A';
            for(int j=1;j<=i;j++)
            {
                System.out.printf("%c \t",(char)c);
                c = c +1 ;
            }
            System.out.print("\n");
        }
    }
    public static void pattern_15(int n)
    {
        for(int i=1;i<=n;i++)
        {
            int c = 'A';
            for(int j=1;j<=n-i+1;j++)
            {
                System.out.printf("%c \t",(char)c);
                c = c +1 ;
            }
            System.out.print("\n");
        }
    }
    public static void pattern_16(int n){
        int ch = 'A';
        for(int i=1;i<=n;i++)
        {
            
            for(int j=1;j<=i;j++)
            {
                System.out.printf("%c\t",(char)ch);
            }
            ch = ch+1;
            System.out.println();
        }
    }
    public static void pattern_17(int n)
    {
        int c = 'A';
        int arr[] = new int[2];
        arr[0] = n;
        arr[1] = n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2*n-1;j++)
            {
                if(j>=arr[0] && j<=arr[1])
                {
                    if(j!=n)
                    {
                        System.out.printf("%c\t",(char)(c-Math.abs(n-j)));
                    }
                    else
                    {
                        System.out.printf("%c\t",(char)c);
                    }
                }
                else
                {
                    System.out.print("\t");
                }
                
            }
            c= c+ 1;
            arr[0] = arr[0]-1;
            arr[1]= arr[1] + 1;
            System.out.print(" \n");
        }
    }
    public static void pattern_18(int n)
    {
        int ch = 'A'+n-1;
        for(int i=1;i<=n;i++)
        {
            int temp_ch = ch;
            for(int j=1;j<=i;j++)
            {
                System.out.printf("%c\t",(char)temp_ch);
                temp_ch = temp_ch + 1;
            }
            System.out.println();
            ch = ch -1;
        }
    }
    public static void pattern_19_1(int n)
    {
        int arr[] = new int[2];
        arr[0] = 2;
        arr[1] = 2*n-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2*n;j++)
            {
                if(j>=arr[0] && j<=arr[1])
                {   
                    
                    System.out.print(" \t");
                }
                else
                {
                    
                    System.out.print("*\t");
                }
            }
            System.out.print("\n");
            arr[0] = arr[0] + 1;
            arr[1] = arr[1] - 1;
        }
    }
    public static void pattern_19_2(int n)
    {
        int arr[] = new int[2];
        arr[0] = -1;
        arr[1] = -1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2*n;j++)
            {
                if(arr[0] == -1 && arr[1] == -1)
                {
                    System.out.print("*\t");
                }
                else if(j>=arr[0] && j<=arr[1])
                {   
                    System.out.print(" \t");
                }
                else
                {
                    System.out.print("*\t");
                }
            }
            System.out.print("\n");
            if(arr[0] == -1 && arr[1] == -1)
            {
                arr[0] = n;
                arr[1] = n+1;
            }
            else
            {
                arr[0] = arr[0] - 1;
                arr[1] = arr[1] + 1;
            }
        }
    }
    public static void pattern_19(int n)
    {
        pattern_19_1(n/2);
        pattern_19_2(n/2);
    }
    public static void pattern_20(int n)
    {
        pattern_19_2(n/2);
        pattern_19_1(n/2);
    }
    public static void pattern_21(int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==1 || j == 1 || j == n || i == n)
                {
                    System.out.print("*\t");
                }
                else
                {
                    System.out.print("\t");
                }
            }
            System.out.println();
        }
    }
    public static void pattern_22(int n)
    {
        int row_value = n;
        int arr [] = new int [2];
        arr[0]=1;
        arr[1] = 2*n-1;
        for(int i=1;i<=2*n-1;i++)
        {
            for(int j=1;j<=2*n-1;j++)
            {
                if(j>=arr[0] && j<=arr[1])
                {
                    System.out.printf("%d\t",row_value);
                }
                else
                {
                    System.out.printf("%d\t",Math.abs(n-j)+1);
                }
            }
            
            if(i<n)
            {
                arr[0] = arr[0] + 1;
                arr[1] = arr[1] - 1;
                row_value = row_value - 1;
            }
            else
            {
                arr[0] = arr[0] - 1;
                arr[1] = arr[1] + 1;
                row_value = row_value + 1;
            }
            
            System.out.print("\n");
        }
    }
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter the No of Rows");
            int n = sc.nextInt();
            //pattern_1(n);
            //pattern_2(n);
            //pattern_3(n);
            //pattern_4(n);
            //pattern_5(n);
            //pattern_6(n);
            //pattern_7(n);
            //pattern_8(n);
            //pattern_9(n);
            //pattern_10(n);
            //pattern_11(n);
            //pattern_12(n);
            //pattern_13(n);
            //pattern_14(n);
            //pattern_15(n);
            //pattern_16(n);
            //pattern_17(n);
            //pattern_18(n);
            //pattern_19(n);
            //pattern_20(n);
            //pattern_21(n);
            pattern_22(n);
        }
    }
}