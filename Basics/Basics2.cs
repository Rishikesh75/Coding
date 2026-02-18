using System;
public class Basic
{
    public static void Main(string[] args)
    {
        // int i;
        // long l;

        // double d;
        // float f;
        
        // string s;
        // char c;

        // int.TryParse(Console.ReadLine(),out i);
        // long.TryParse(Console.ReadLine(),out l);

        // double.TryParse(Console.ReadLine(),out d);
        // float.TryParse(Console.ReadLine(),out f);

        // s = Console.ReadLine();
        // string temp = Console.ReadLine();
        // c = temp[0];

        // Console.WriteLine("int:{0} long:{1} double:{2} float:{3} string:{4} char:{5}",i,l,d,f,s,c);


        int num1,num2;

        num1 = int.Parse(Console.ReadLine());
        num2 = int.Parse(Console.ReadLine());

        
        Console.WriteLine("{0} {1} {2} {3}",num1+num2,num1-num2,num1*num2,num1/num2);

        double d =  num1;
        Console.WriteLine("double:{0}",d);

        num1 = num1 - num2;
        num2 = num1 + num2;
        num1 = num2 - num1;

        Console.WriteLine("Number val:{0} Number val:{1}",num1,num2);


        int asciValue = 'a';
        Console.WriteLine("ASCIVALUE:{0}",asciValue);
    }
}