import java.util.Scanner;

public class Basics2 {
    
    public static int sum(int a,int b)
    {
        return a+b;
    }

    public static int difference(int a,int b)
    {
        return a-b;
    }

    public static int mutiply(int a,int b)
    {
        return a*b;
    }

    public static double divison(int a, int b) {
    if (b == 0) {
        throw new IllegalArgumentException("Division by zero not allowed");
    }

    return (double) a / b;
    }

    public static  void swap(int[] arr){
        Integer temp = arr[1];
        arr[1] = arr[0];
        arr[0] = temp;
        return;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

    //     byte b = Byte.parseByte(sc.nextLine());
    //     short sh = Short.parseShort(sc.nextLine());
    //     int i = Integer.parseInt(sc.nextLine());
    //     long l = Long.parseLong(sc.nextLine());

    //     char c = sc.nextLine().charAt(0);
    //     String s = sc.nextLine();

    //     double d = Double.parseDouble(sc.nextLine());
    //     float f = Float.parseFloat(sc.nextLine());

    //     boolean bool = true;

    //    System.out.printf("%d %d %d %d %c %s %f %f %b",b,sh,i,l,c,s,d,f,bool);

    //    System.out.printf("%d %d %d %.2f",sum(1,2),difference(1,2),mutiply(2, 3),divison(4, 5));

    // Integer i1 = 1;
    // Integer i2 = 2;
    // double doub = (double) i1;
    
    // System.out.printf("%d %d",i1,i2);
    // swap(i1,i2);

    // System.out.printf("%d %d",i1,i2);

    // int i = (char) 'A';

    // System.out.printf("ASCI Value:%d",i);

    int[] arr = {1,2};
    
    System.out.printf("%d %d",arr[0],arr[1]);
    swap(arr);
    System.out.printf("%d %d",arr[0],arr[1]);

    }
}
