
import java.lang.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
//Two Pointer problems
public class Array2 {
    

    public static List<Integer> createArr()
    {
        return  new ArrayList<>(List.of(1,1,1,1,2,3,4,5));
    }

    public static int maxSumK(List<Integer> list,int k){
        int n = list.size();
        
        int i = 0;
        int j = 0;
        int sum = 0;
        int maxSum = Integer.MIN_VALUE;

        while(j<n){

            //Expand the Window
            while(j<n && j-i+1<=k){
                sum += list.get(j);
                
                if(j-i+1 == k){
                    maxSum = Math.max(maxSum, sum);
                    break;
                }

                j++;

            }

            //Shrink the window
            while(i<=j && j-i+1 >=k){
                sum = sum - list.get(i);
                i++;
            }

            j++;

        }
        return maxSum;
    }

    public static int minSum(List<Integer> list,int k){
        int n = list.size();

        int i = 0;
        int j = 0;
        int sum = 0;
        int minSum = Integer.MAX_VALUE;

        while(j<n){


            //ExpandWindow
            while(j<n && j-i+1<=k){
                sum += list.get(j);
                
                if(j-i+1 == k){
                    minSum = Math.min(sum,minSum);
                    break;
                }

                j++;
            }


            //CompressWindow
            while(i<=j && j-i+1>=k){
                sum -= list.get(i);
                i++;
            }

            j++;

        }

        return minSum;

    }

    public static int countSubArrays(List<Integer> list,int k,int averageX){
        int n = list.size();

        int i = 0;
        int j = 0;
        int sum = 0;
        int count = 0;

        while(j<n){
            while(j<n && j-i+1<=k){
                sum +=list.get(j);

                if(j-i+1 == k){
                    if(sum >= averageX * k){
                        count++;
                    }
                    break;
                }

                j++;
            }

            while(i<=j && j-i+1>=k){
                sum -= list.get(i);
                i++;
            }

            j++;
        }

        return count;
    }

    public static boolean isVowel(char ch){
        ch = Character.toLowerCase(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    public static int maxNoOfVowels(String s,int k){

        int n = s.length();

        int i = 0;
        int j = 0;
        int count = 0;
        int maxCount = 0;
        while(j<n){

            //ExpandWindow
            while(j<n && j-i+1<=k){
                if(isVowel(s.charAt(j)))
                    count++;

                if(j-i+1 == k){
                    maxCount = Math.max(maxCount,count);
                    break;
                }

                j++;

            }

            //CompressWindow
            while(i<=j && j-i+1>=k){
                if(isVowel(s.charAt(i)))
                    count--;
                i++;
            }
            
            j++;


        }

        return maxCount;
    }
public static int findLongestSubArray(List<Integer> list, int sum) {

    int n = list.size();

    int i = 0;
    int j = 0;
    int len = 0;
    int currSum = 0;

    while (j < n) {

        // Expand Window
        while (j < n && currSum < sum) {
            currSum += list.get(j);

            if (currSum == sum) {
                len = Math.max(len, j - i + 1);
            }

            j++;
        }

        // Compress Window
        while (i <= j && currSum > sum) {
            currSum -= list.get(i);
            i++;

            if (currSum == sum) {
                len = Math.max(len, j - i);
            }
        }
    }

    return len;
}

    public static int longestSubArrayAtMostK(List<Integer> list, int k) {

    int n = list.size();

    int i = 0;
    int j = 0;
    int currSum = 0;
    int maxLen = 0;

    while (j < n) {

        // Expand window
        currSum += list.get(j);

        // Compress window if sum exceeds k
        while (i <= j && currSum > k) {
            currSum -= list.get(i);
            i++;
        }

        // Now currSum <= k always here
        maxLen = Math.max(maxLen, j - i + 1);

        j++;
    }

    return maxLen;
}

    public static int minSubArrayLen(int k, List<Integer> list) {

    int n = list.size();

    int i = 0;
    int j = 0;
    int currSum = 0;
    int minLen = Integer.MAX_VALUE;

    while (j < n) {

        // Expand window
        currSum += list.get(j);

        // Shrink window while condition is satisfied
        while (i <= j && currSum >= k) {
            minLen = Math.min(minLen, j - i + 1);

            currSum -= list.get(i);
            i++;
        }

        j++;
    }

    return (minLen == Integer.MAX_VALUE) ? 0 : minLen;
}

public static List<Integer> firstNegativeInWindow(List<Integer> list, int k) {

    int n = list.size();
    List<Integer> result = new ArrayList<>();
    Queue<Integer> q = new LinkedList<>(); // stores indices of negatives

    int i = 0, j = 0;

    while (j < n) {

        // Add current element if negative
        if (list.get(j) < 0) {
            q.add(j);
        }

        // Window size < k → expand
        if (j - i + 1 < k) {
            j++;
        }

        // Window size == k
        else if (j - i + 1 == k) {

            // Get first negative
            if (!q.isEmpty()) {
                result.add(list.get(q.peek()));
            } else {
                result.add(0);
            }

            // Remove element going out of window
            if (!q.isEmpty() && q.peek() == i) {
                q.poll();
            }

            i++;
            j++;
        }
    }

    return result;
}


    public static void main(String[] args){

        List<Integer> list = createArr();

        System.out.printf("MaxSum of size k:%d\n",maxSumK(list, 3));
        System.out.printf("MinSum of size:%d\n",minSum(list, 3));
        System.out.printf("CountSubArray:%d\n",countSubArrays(list, 3, 3));

        System.out.printf("MaxNoofVowels:%d\n",maxNoOfVowels("faaaafjs fjaslfj",3));
        return;
    }
}
