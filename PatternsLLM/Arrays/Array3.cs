using System;
using System.Collections.Generic;

public class Program
{
    
    public static void Display(List<int>list,int lastIndex)
    {
        int count =0;
        foreach(var val in list)
        {
            if(count == lastIndex+1)
                break;
            
            Console.Write($"{val}");
            count++;
        }
        Console.WriteLine();
        return;
    }
    
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
    
    public static void RemoveDuplicates(List<int>list)
    {
        if(list.Count <= 1) return;

        int lastValidIndex = 0;
        int j = 0;

        while(j<list.Count)
        {
            
            if(list[j] != list[lastValidIndex])
            {
                list[lastValidIndex+1] = list[j];
                lastValidIndex++;      
            }

            j++;
        }

        Display(list,lastValidIndex);
    }

    
    public static void MoveAllZerosToEnd(List<int>list)
    {
        int i=0;
        int j = list.Count-1;

        while(i<j)
        {
            if(list[i] != 0)
            {
                i++;
                continue;
            }
                

            if(list[j] == 0)
            {
                j--;
                continue;
            }

            else if(list[i] ==0 && list[j] != 0)
            {
                var temp = list[i];
                list[i] = list[j];
                list[j]  = temp;

                i++;
                j--;
            }   
        }

        Display(list,list.Count-1);

        return;

    }


    //Insertion Need To Maintianed
    public static void MoveAllZerosToEndI(List<int>list)
    {
        int i=0;
        int lastValidIndex = 0;
        int n = list.Count;

        while(i<n)
        {
            if(list[i] == 0)
            {
                int j =i;
                
                while(j<n && list[j]==0)
                {
                    j++;
                }
                if(i == j || j>=n) break;

                var temp = list[lastValidIndex+1];
                list[lastValidIndex+1] = list[j];
                list[j] = temp;
                
                lastValidIndex++;
                j++;
                i = j;
                continue;
            }

            if(list[i]!=0 && lastValidIndex < i)
            {
                list[lastValidIndex+1] = list[i];
                list[i] = 0;
                i++;
                lastValidIndex++;
                continue; 
            }

            i++;
            if(i<n && list[i]!=0)
                lastValidIndex++;
        }

        Display(list,list.Count-1);

    }


    public static void ReverseArr(List<int> list)
    {
        int i=0;
        int j = list.Count-1;
        while(i<j)
        {
            int temp = list[i];
            list[j] = list[i];
            list[i] = temp;
            
            i++;
            j--;
        }

        return;
    }
    public static void Main(string[] args)
    {
        
            Console.WriteLine($"{TwoSum(new List<int>(){1,2,3,4},5)}");


            var list = new List<int>(){1,3,2,4,5};
            list.Sort();

            Console.WriteLine($"{TwoSum(list,7)}");


            RemoveDuplicates(new List<int>(){1,1,1,2,2,3,4,4,5});

            MoveAllZerosToEnd(new List<int>(){1,0,0,1,0,0,2,2,3,4});

            MoveAllZerosToEndI(new List<int>(){1,0,0,1,0,0,2,2,0,0});
    }
}