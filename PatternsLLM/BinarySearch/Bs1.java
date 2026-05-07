class GuessNumber
{
    private int value;
    public GuessNumber(int value){
        this.value = value;
    }
    
    private int guess(int number){
        if(value == number) return 0;
        
        else if(value > number) return 1;
        
        else if(value < number) return -1;
        
        return Integer.MAX_VALUE;
    }
    
    
    public int guessNumber(int n){
        
        int start = 0;
        int end = n;
        
        while(start<end){
            
            int mid = start + (end - start)/2;
            
            int res = guess(mid);
            
            if(res == 0)
                return mid;
            
            else if(res == 1)
                end = mid - 1;
            
            else if(res == -1)
                start = mid + 1;
        }
        
        return -1;
    }   
}

public class Bs1{
    
    public static int bs1(int[] arr,int k,int start,int end){
        
        if(start>end) return -1;
        
        int mid = start + (end - start)/2;
        
        if(arr[mid] == k) return mid;
        
        else if(arr[mid]<k) return bs1(arr,k,mid+1,end);
        
        else return bs1(arr,k,start,mid-1);
    }
    
    public static int bs2(int[] arr,int k){
        int start = 0;
        int end = arr.length - 1;
        
        while(start<=end){
            
            int mid = start + (end - start)/2;
            
            if(arr[mid] == k)   return mid;
            
            else if(arr[mid]<k) start = mid+1;
            
            else if(arr[mid]>k) end = mid - 1;
        }
        
        return -1;
    }
    
    public static int searchInsertedPostion(int[] arr,int k){
        int start = 0;
        int end = arr.length - 1;
        
        while(start<=end){
            
            int mid = start + (end - start)/2;
            
            if(arr[mid] == k)
                return mid;
            
            else if(arr[mid]>k)
                end =  mid - 1;
            
            else
                start = mid + 1;
        }
        
        return start;
    }
    
    public static int findBadVersion(char[] version)
    {
        int start = 0;
        int end = version.length;
        int ans = -1;
        while(start<=end){

            int mid = start + (end - start)/2;

            if(version[mid] == 'G')
            {
                start = mid + 1;
            }

            else if(version[mid] == 'B')
            {
                ans = mid;
                end = mid-1;
            }

        }

        return ans;
    }

    public static void main(String[] args){
        
        System.out.printf("Index(Recurssion):%d\n",bs1(new int[]{1,2,3,4},2,0,3));
        System.out.printf("Index(Iterative):%d\n",bs2(new int[]{1,2,3,4},2));
        
        System.out.printf("InsertPostion:%d\n",searchInsertedPostion(new int[]{1,1,3,4},1));
        
        GuessNumber game = new GuessNumber(5);
        System.out.printf("Guessed Number:%d\n",game.guessNumber(10));
        

        System.out.printf("firstBadVersion:%d\n",findBadVersion(new char[]{'G','G','G','B'}));
        return;
    }
}