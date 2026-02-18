public class Basic4
{
    
    public static void calc()
    {
        int.TryParse(Console.ReadLine(),out int num1);
        int.TryParse(Console.ReadLine(),out int num2);
        char c  = Console.ReadLine()[0];
        int ans =0;
        switch(c)
        {
            case '+':
                ans = num1+num2;
                break;
            case '-':
                ans = num1-num2;
                break;
            case '*':
                ans = num1*num2;
                break;          
            case '/':
                ans = num1/num2;
                break;
            default:
                break;
        }
        Console.WriteLine($"value:{ans}");
    }

    public static bool isVowel(char c)
    {
        bool vw ;
        switch(c)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vw = true;
                break;
            default:
                vw = false;
                break;
        }
        return vw;
    }

    public static char calcGrade(int val)
    {
       if(val >=90) return 'A';
       else if(val>=81) return 'B';
       else if(val>=71) return 'C';
       return 'F';
    }
    public static void Main(string[] args)
    {

        
    }
}