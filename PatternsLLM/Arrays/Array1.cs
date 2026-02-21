using System;
using System.Collections.Generic;
public class Program
{
    
    public static int FindLargestElement(List<int> arr)
    {
        int val = int.MinValue;
        for(int i=0;i<arr.Count;i++)
        {
            val = Math.Max(val,arr[i]);
        }
        return val;
    }
    
    public static  int FindSecondLargestElement(List<int>arr)
    {
        int val1 = arr[0];
        int val2 = int.MinValue;
        
        for(int i=0;i<arr.Count;i++)
        {
            if(arr[i] > val1)
            {
                val2 = val1;
                val1 = arr[i];
            }
            else if(arr[i] > val2)
                val2 = arr[i];    
        }
        return val2;
    }

    public static bool IsSorted(List<int>arr)
    {
        bool isAscendingOrder = arr[0] < arr[1] ? true : false;
        if(isAscendingOrder)
        {
            for(int i=1;i<arr.Count;i++)
            {
                if(arr[i] < arr[i-1])
                {
                    return false;
                }
            }  
        }
        else
        {
            for(int i=1;i<arr.Count;i++)
            {
                if(arr[i] > arr[i-1])
                {
                    return false;
                }
            }  
        }
        return true;
    }

    public static (int EvenCount,int OddCount) CountEvenOdd(List<int>arr)
    {
        int evenCount = 0;
        int oddCount = 0;
        foreach(var val in arr)
        {
            if(val % 2 == 0)
                evenCount++;
            else
                oddCount++;
        }
        return (evenCount,oddCount);
    }

    public static void ReversedArr(List<int>arr)
    {
        int i=0;
        int j = arr.Count-1;
        while(i<j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            
            i++;
            j--;
        }
        Display(arr);
    }

    public static void RemoveDuplicatesSortedArr(List<int>arr)
    {
        int lastValidIndex = 0;
        int i= 1;
        while(i<arr.Count)
        {

            if(arr[i]!=arr[lastValidIndex])
            {
                int temp =arr[lastValidIndex+1];
                arr[lastValidIndex+1] = arr[i];
                arr[i] = arr[lastValidIndex+1];
                lastValidIndex++;
            }
            i++;
        }
        Display(arr,lastValidIndex);
    }

    public static bool IsPlamindrome(List<int>arr)
    {
        int i = 0;
        int j = arr.Count - 1;
        while(i!=j)
        {
            if(arr[i] != arr[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    public static void Display(List<int>arr)
    {
        Console.WriteLine("Elements in the Array");
        foreach(var val in arr)
        {
            Console.Write($"{val}\t");
        }
        Console.WriteLine();
    }

    public static void Display(List<int>arr,int n)
    {
        Console.WriteLine("Elements in the Array");
        
        foreach(var val in arr)
        {
            if(n == -1) break;
            Console.Write($"{val}\t");
            n--;
        }
        Console.WriteLine();

    }

    public static int FindMissingNumber(List<int>arr)
    {
        int sum = 0;
        int n = arr.Count;
        foreach(int val in arr)
        {
            sum = sum + val;
        }
        return (n*(n-1)/2) - sum;
    }

    public static void MovesZerosToEnd(List<int>arr)
    {
        int i=0;
        int j = arr.Count - 1;

        while(i < j)
        {
            if(arr[i] != 0)
            {
                i++;
                continue;
            }
            else if(arr[j] == 0)
            {
                j--;
                continue;
            }
            else
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;    
            }
        }

        Display(arr);
    }

    public static void CountFrequency(List<int>arr)
    {
        Dictionary<int,int>dict = new Dictionary<int, int>();

        foreach(int val in arr)
        {
            if(dict.ContainsKey(val))
            {
                dict[val] = dict[val] + 1;
            }
            else dict.Add(val,1);
        }


        foreach(KeyValuePair<int,int> kvp in dict)
        {
            Console.WriteLine($"Number:{kvp.Key} Count:{kvp.Value}");
        }
        return;
    }
    public static void Main(string[] args)
    {
        Console.WriteLine($"LargestElement:{FindLargestElement(new List<int>{1,2,3})}");
        Console.WriteLine($"SecondLargestElement:{FindSecondLargestElement(new List<int>{1,2,3})}");
        Console.WriteLine($"IsSorted:{IsSorted(new List<int>{1,2,3})}");
        
        var count = CountEvenOdd(new List<int>{1,2,3});
        Console.WriteLine($"EvenCount:{count.EvenCount} OddCount:{count.OddCount}");

        List<int>list = new List<int>(){1,2,3};
        ReversedArr(list);
        Display(list);

        RemoveDuplicatesSortedArr(new List<int>(){1,2,3,4,5});

        list = new List<int>(){1,2,1};
        Console.WriteLine($"IsPalimdrome:{IsPlamindrome(new List<int>(){1,2,1})}");

        Console.WriteLine($"MissingNumber:{FindMissingNumber(new List<int>(){0,1,2})}");

        MovesZerosToEnd(new List<int>(){1,2,3,4});

        CountFrequency(new List<int>(){1,2,3,1,2});
    }

}