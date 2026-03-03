using System;
using System.Collections.Generic;

public class Program
{
    
    public static bool TwoSum(List<int> list,int sum)
    {
        int i = 0;
        int j = list.Count - 1;

        while(i<j)
        {
            if(list[i] + list[j] == sum)
                return true;

            else if(list[i] + list[j] > sum)
                j--;
            
            else
                i++;
        }

        return false;
    }
    
    public static void Main(string[] args)
    {
        
            Console.WriteLine($"{TwoSum(new List<int>(){1,2,3,4},5)}");


            var list = new List<int>(){1,3,2,4,5};
            list.Sort();

            Console.WriteLine($"{TwoSum(list,7)}");

    }
}