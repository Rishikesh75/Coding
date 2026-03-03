//Linear Recurssion

public class Program
{
    public static void Recurssion1(int n)
    {
        if(n == 0)
            return;

        Recurssion1(n-1);
        Console.Write(n);
        
        return;
    }

    public static void Recurssion2(int n)
    {
        
        if(n==0)
            return;

        Console.Write(n);
        Recurssion2(n-1);
    }

    public static List<int>? list;
    public static int sum = 0;
    public static void SumArr(int index)
    {
        if(index == list.Count)
            return;
        
        sum += list[index];
        index++;
        SumArr(index);
    }

    public static bool IsPlaimdrome(string s,int start,int end)
    {
        if(start>=end)
            return true;
        
        if(s[start] != s[end])
            return false;

        return IsPlaimdrome(s,start+1,end-1);
    }

    public static void ReverseArr(int[] arr,int start,int end)
    {
        if(start >= end)
            return;

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] =temp;

        ReverseArr(arr,start+1,end-1);

    }
    public static void Main(string[] args)
    {
        int.TryParse(Console.ReadLine(),out int n);
        
        Recurssion1(n);
        Console.WriteLine();
        
        Recurssion2(n);
        Console.WriteLine();
        list = new List<int>(){1,2,3,4,5};

        SumArr(0);
        Console.WriteLine($"Sum of Arr:{sum}");

        string str = Console.ReadLine();
        Console.WriteLine($"IsPalimdrome:{IsPlaimdrome(str,0,str.Length-1)}");

        int[] arr = new int[2]{1,2};
        ReverseArr(arr,0,arr.Length-1);

        foreach(var val in arr)
        {
            Console.Write(val);
        }

    }

}