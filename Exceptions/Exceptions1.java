
import java.util.Scanner;

public class Exceptions1 {

    public static void main(String[] args)
    {
        
        Scanner sc = new Scanner(System.in);
        int val1 = Integer.parseInt(sc.nextLine());
        try{
            if(val1 <0)
                throw new Exception("This is the negative number");
        }
        catch(Exception ex)
        {
            System.out.printf("Exception is catched here....%s %s",ex.getMessage(),ex.toString());
            System.err.println();
            ex.printStackTrace();
        }
        
        
        return;
    }

}
