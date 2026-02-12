import java.util.*;
public class Basics7 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] arr = new int[n];

        for(int i=0;i<n;i++) {
            arr[i] = sc.nextInt();
        }

        for(int i=0;i<n;i++){
            System.out.printf("%d\t",arr[i]);
        }
        System.out.println();

        int sum = 0;
        int largest = Integer.MIN_VALUE;
        int smallest = Integer.MAX_VALUE;
        boolean isSorted = true;
        int secondLargest = Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            sum = sum + arr[i];

            if(arr[i] > largest){
                secondLargest = largest;
                largest = arr[i];
            }
            else if(arr[i]>secondLargest){
                secondLargest = arr[i];
            }

            smallest = Math.min(arr[i],smallest);
            if(i>=1) {
                if(arr[i-1]>arr[i]){
                    isSorted = false;
                }
            }
        }
        System.out.printf("Sum:%d largest:%d smallest:%d secondlargest:%d isSorted:%b\n",sum,largest,smallest,secondLargest,isSorted);

        int start = 0;
        int end = arr.length-1;
        while(start<end) {
            arr[start] = arr[start] - arr[end];
            arr[end] = arr[start] + arr[end];
            arr[start] = arr[end] - arr[start];

            start++;
            end--;
        }

        for(int i=0;i<n;i++){
            System.out.printf("%d\t",arr[i]);
        }
        System.out.println();

        int val = arr[0];

        for(int i=1;i<arr.length;i++){
            arr[i-1] = arr[i];
        }
        arr[arr.length-1] = val;

        for(int i=0;i<n;i++){
            System.out.printf("%d\t",arr[i]);
        }
        System.out.println();

        Map<Integer,Integer> map = new HashMap<>();

        for(int i=0;i<n;i++){
            if(!map.containsKey(arr[i])) {
                map.put(arr[i],1);
                continue;
            }
            map.replace(arr[i],map.get(arr[i])+1);
        }
        Set<Integer> set = new HashSet<>();
        for(var row : map.entrySet()){
            if(row.getValue() == 1) set.add(row.getKey());
            System.out.printf("key:%d value:%d\n",row.getKey(),row.getValue());
        }
        System.out.print("Unique values:");
        for(var item : set){
            System.out.printf("%d",item);
        }
    }
}