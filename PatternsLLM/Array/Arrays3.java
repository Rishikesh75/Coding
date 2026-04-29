import java.util.*;
public class Arrays3
{
    public static class Pair
    {
        Integer first;
        Integer second;
        
        public Pair(Integer first,Integer second){
            this.first = first;
            this.second = second;
        }
    }
    
    //SortedArray
    public static Pair twoSum(List<Integer> list,int sum){
        Pair pair = new Pair(-1,-1);
        
        int i = 0;
        int j = list.size()-1;
        
        
        while(i<j){
            int currSum = list.get(i) + list.get(j);
            
            if(currSum == sum)
            {
                pair.first = i;
                pair.second = j;
                break;
            }
            
            else if(currSum > sum){
                j--;
                continue;
            }
            
            i++;
        }
        
        return pair;
    }
    
    //Hashing Pattern
    public static Pair twoSum1(List<Integer> list,int sum){
        Pair pair = new Pair(-1,-1);
        Map<Integer,Integer> map = new HashMap<>();
            
        for(int i=0;i<list.size();i++){
            
            if(map.containsKey(sum - list.get(i)))
            {
                pair.first = map.get(sum-list.get(i));
                pair.second = i;
                break;
            }
            
            map.put(list.get(i),i);
            
        }
        
        return pair;
        
    }
    
    public static void display(List<Integer> list)
    {
        System.out.print("values:");
        for(var val : list){
            System.out.printf("%d\t",val);
        }
        System.out.println();
    }
    
    public static void reverseArray(List<Integer> list){
        
        int i = 0;
        int j = list.size()-1;
        
        while(i<j){
            
            int temp = list.get(i);
            list.set(i,list.get(j));
            list.set(j,temp);
            
            i++;
            j--;
            
        }
        
        display(list);
    }
    
    //Remove Duplicates
    
    public static void removeDuplicates(List<Integer> list){
        
        list.sort((Integer x1,Integer x2) -> x1-x2);
        
        int lastValidIndex = 0;
        int val = list.get(lastValidIndex);
        
        for(int i = 1;i<list.size();i++){
            if(list.get(i) != val){
                int temp = list.get(i);
                list.set(lastValidIndex+1,temp);
                list.set(i,temp);
                lastValidIndex++;
            }
        }
        
        System.out.print("values:");
        for(int i=0;i<=lastValidIndex;i++){
            System.out.printf("%d",list.get(i));
        }
        System.out.println();
        
        
    }
    
    
    //Move Zeros to end
    
    public static void moveZeros(List<Integer> list){
        
        int j = 0;
        for(int i = 0;i<list.size();i++){
            if(list.get(i)!=0){
                int temp = list.get(i);
                list.set(i,list.get(j));
                list.set(j,temp);
                j++;
            }
        }
        
        System.out.print("values:");
        for(int i=0;i<list.size();i++){
            System.out.printf("%d\t",list.get(i));
        }
        System.out.println();
        
    }
    
    //Container with Most Water
    
    public static int containerWithMostWater(List<Integer> list){
        
        int i = 0;
        int j = list.size()-1;
        int maxWater = Integer.MIN_VALUE;
        
        
        while(i<j){
            
            int currValue = Math.abs(list.get(j) - list.get(i)) * (j - i + 1);
            maxWater = Math.max(currValue,maxWater);
            
            if(list.get(i)>list.get(j))
                j--;
            else 
                i++;
        }
        
        return maxWater;
    }
    //Trapping Rain Water
    public static int trappingRainWater(List<Integer> list){
        int left = 0;
        int right = list.size()-1;
        
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;
        
        while(left<right){
            if(list.get(left)<list.get(right)){
                if(list.get(left) > leftMax)
                    leftMax = list.get(left);
                else
                    water += leftMax - list.get(left);
                
                left++;
            }
            
            else{
                if(list.get(right) > rightMax)
                    rightMax = list.get(right);
                else
                    water += rightMax - list.get(right);
                    
                right--;
            }
        }
        
        return water;
        
        
    }
    
    public static List<Integer> squaresSortedArray(List<Integer> list){
        int i = 0;
        int j = list.size()-1;
        
        var ans = new ArrayList<Integer>(Collections.nCopies(list.size(),0));
        int k = list.size()-1;
        while(i<=j){
            if(Math.abs(list.get(i)) > Math.abs(list.get(j))){
                ans.set(k,list.get(i) * list.get(i));
                i++;
            }
            else{
                ans.set(k,list.get(j) * list.get(j));
                j--;
            }
            k--;
        }
        
        System.out.print("values:");
        for(var val : ans){
            System.out.printf("%d\t",val);
        }
        System.out.println();
        
        return ans;
    }
    public static void main(String[] args){
        
        
        var ans = twoSum(new ArrayList<Integer>(List.of(-1,2,3,4,5)),6);
        System.out.printf("Index1:%d Index2:%d\n",ans.first,ans.second);
        
        
        ans = twoSum1(new ArrayList<Integer>(List.of(-1,2,3,4,5)),6);
        System.out.printf("Index1:%d Index2:%d\n",ans.first,ans.second);
        
        reverseArray(new ArrayList<Integer>(List.of(-1,2,3,4,5)));
        
        
        removeDuplicates(new ArrayList<Integer>(List.of(1,1,1,1,2,3,4)));
        
        moveZeros(new ArrayList<Integer>(List.of(1,0,1,1,1,1,0)));
        
        System.out.printf("%d\n",containerWithMostWater(new ArrayList<Integer>(List.of(0,1,0,0,2,1,0,1,3,2,1,2,1))));
        
        System.out.printf("Trapping RainWater:%d\n",trappingRainWater(new ArrayList<Integer>(List.of(0,1,0,2,1,0,1,3,2,1,2,1))));
        
        squaresSortedArray(new ArrayList<Integer>(List.of(-11,1,2,3,4)));
        return;
    }
}