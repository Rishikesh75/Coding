import java.util.*;
public class Basics4
{
    public static void main(String[] args)
    {
       Scanner sc = new Scanner(System.in);

       int val1 = sc.nextInt();
       char c = sc.next().charAt(0);
       int val2 = sc.nextInt();

       switch(c)
       {
           case '+':
           {
               System.out.printf("Add:%d\n",val1+val2);
               break;
           }
           case '-':
           {
               System.out.printf("Sub:%d\n",val1-val2);
               break;
           }
           case '*':
           {
               System.out.printf("Mul:%d\n",val1*val2);
               break;
           }
           case '/':
           {
               System.out.printf("Div:%f\n",(double)val1/val2);
               break;
           }
           default:
           {
               System.out.printf("Not Supported..");
               break;
           }

       }

       c = sc.next().charAt(0);
       switch (c)
       {
           case 'a':
           case 'A':
           case 'e':
           case 'E':
           case'i' :
           case 'I':
           case 'o':
           case 'O':
           case 'u':
           case 'U':
           {
               System.out.println("Is Vowel..\n");
               break;
           }
           default:
           {
               System.out.println("Is Consonent..\n");
               break;
           }
       }


       int marks = sc.nextInt();

       if(marks>90)
       {
           System.out.println("A");
       }
       else if(marks<90)
       {
           System.out.println("Not A");
       }
    }
}