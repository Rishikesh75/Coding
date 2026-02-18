using System;
using System.Text;
public class Basics8
{
    public static string ReferenceString(string s)
    {
        StringBuilder sb = new StringBuilder(s);
        int i=0;
        int j = s.Length-1;
        while(i<j)
        {
            char c = sb[i];
            sb[i] = sb[j];
            sb[j] = c;

            i++;
            j--;
        }
        return sb.ToString();
    }
    
    public static bool IsPlaimdrome(string s)
    {
        StringBuilder sb = new StringBuilder(s);
        int i=0;
        int j= s.Length - 1;
        while(i<j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;

        }
        return true;
    }

    public static (int CVowels,int CConsonents) CountChar(string s)
    {
        int cVowels = 0;
        int cConsonents= 0;
        foreach(char c in s)
        {
            if("aeiou".Contains(c))
            {
                cVowels++;
                continue;
            }
            cConsonents++;
        }
        return (cVowels,cConsonents);
    }

    public static int add(int a,int b)
    {
        return a+b;
    }

    public static double add(double a,double b)
    {
        return a+b;
    }
    public static void Main(string[] args)
    {
        string s = Console.ReadLine();
        s = ReferenceString(s);
        Console.WriteLine($"Reversed String:{s}");
    }
}