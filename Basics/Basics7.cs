using System;
public class Basics8
{
    public static int[] createarr(int n)
    {
        int[] arr = new int[n];
        for(int i=0;i<n;i++)
        {
            int.TryParse(Console.ReadLine(),out arr[i]);
        }
        return arr;
    }
    
    public static int sum(ref int[] arr)
    {
        int val = 0;
        for(int i=0;i<arr.Length;i++)
        {
            val = val + arr[i];
        }
        return val;
    }

    public static (int largest,int smallest) FindVal(ref int[] arr)
    {
        int largest = int.MinValue;
        int smallest = int.MaxValue;
        for(int i=0;i<arr.Length;i++)
        {
            largest = Math.Max(largest,arr[i]);
            smallest = Math.Min(smallest,arr[i]);
        }
        return(largest,smallest);
    }
    public static void Display(ref int[] arr)
    {
        foreach(int val in arr)
        {
            Console.Write($"{val}\t");
        }
        Console.WriteLine();
    }
    public static void ReverseArr(ref int[] arr)
    {
        int i=0;
        int j= arr.Length-1;
        while(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    public static bool isSorted(ref int[] arr)
    {
        string s = arr[0] > arr[1] ? "Inc": "Desc" ;

        if(s == "Inc")
        {
            for(int i=1;i<arr.Length;i++)
            {
                if(arr[i] > arr[i-1]) return false;
            }
        }
        else if(s == "Desc")
        {
            for(int i=1;i<arr.Length;i++)
            {
                if(arr[i] < arr[i-1]) return false;
            }
        }
        return true;
    }

    public static int secondLargestElement(ref int[] arr)
    {
        int secondL = int.MinValue;
        int firstL = arr[0];
        for(int i=1;i<arr.Length;i++)
        {
            if(arr[i] > firstL)
            {
                secondL = firstL;
                firstL = arr[i];
            }
            else if(arr[i] > secondL) secondL = Math.Max(secondL,arr[i]);
        }
        return secondL;
    }

    public static void rotateArr(ref int[] arr)
    {
        int val = arr[0];
        for(int i=1;i<arr.Length;i++)
        {
            arr[i-1] = arr[i];
        }
        arr[arr.Length-1] = val;
        return;
    }
    
    public static void Main(string[] args)
    {
        int.TryParse(Console.ReadLine(),out int n);
        
        int[] arr = createarr(n);

        var temp = FindVal(ref arr);

        Console.WriteLine($"Sum:{sum(ref arr)} largest:{temp.largest} smallest:{temp.smallest}");

        ReverseArr(ref arr);
        Display(ref arr);
        rotateArr(ref arr);
    }
}