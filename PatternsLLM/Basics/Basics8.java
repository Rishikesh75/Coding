import java.util.*;
public class Basics8 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
//        String str = sc.next();
        StringBuilder sb = new StringBuilder();
//        System.out.println(sb.toString());
//
//        int i = 0;
//        int j = sb.length()-1;
//        while(i<j) {
//            char c = sb.charAt(i);
//            sb.setCharAt(i,sb.charAt(j));
//            sb.setCharAt(j,c);
//            i++;
//            j--;
//        }
//        System.out.printf("Reversed String:%s\n",sb.toString());
//
//        boolean isPlaindrome = true;
//
//        sb.setLength(0);
//        sb.append(str);
//         i=0;
//         j = sb.length()-1;
//        while(i<j){
//            if (sb.charAt(i) != sb.charAt(j)) {
//                isPlaindrome = false;
//                break;
//            }
//            i++;
//            j--;
//        }
//        System.out.printf("Is plaindrome:%b\n",isPlaindrome);
//
//        int vowelCount = 0;
//        int consonentCount = 0;
//        for(i=0;i<sb.length();i++){
//            if(sb.charAt(i) == 'A' || sb.charAt(i) == 'E' || sb.charAt(i) == 'I' || sb.charAt(i) == 'O' || sb.charAt(i) == 'U' || sb.charAt(i) == 'a' || sb.charAt(i) == 'e' || sb.charAt(i) == 'i' || sb.charAt(i) == 'o' || sb.charAt(i) == 'u'){
//                vowelCount++;
//                continue;
//            }
//            consonentCount++;
//        }
//        System.out.printf("vowel-count:%d consonent-count:%d",vowelCount,consonentCount);
//
//        List<Integer> list = new ArrayList<>(Collections.nCopies(26,0));
//
//        boolean isAnoram = true;
//        String str1 = sc.next();
//        String str2 = sc.next();
//        StringBuilder sb1 = new StringBuilder(str1);
//        StringBuilder sb2 = new StringBuilder(str2);
//        if(sb1.length() != sb2.length()){
//            isAnoram = false;
//        }
//        else {
//            for(i=0;i<sb1.length();i++){
//                list.set(sb1.charAt(i) - 'a', list.get(sb1.charAt(i) - 'a') + 1);
//
//                list.set(sb2.charAt(i) - 'a', list.get(sb2.charAt(i) - 'a') - 1);
//            }
//        }
//
//        for(var co : list){
//            if(co != 0){
//                isAnoram  =false;
//            }
//        }
//
//        System.out.printf("Is Anagorm:%b",isAnoram);

        String str = sc.nextLine();

        sb.setLength(0);
        sb.append(str);
//
//        for(int i = sb.length() - 1; i >= 0; i--){
//            if(sb.charAt(i) == ' '){
//                sb.deleteCharAt(i);
//            }
//        }
//
//        System.out.printf("Removed spaces: %s", sb.toString());
        Map<Character,Integer> map = new HashMap<>();
        for(int i=0;i<sb.length();i++){
            if(!map.containsKey(sb.charAt(i))){
                map.put(sb.charAt(i),1);
                continue;
            }
            int val = map.get(sb.charAt(i));
            map.replace(sb.charAt(i),val+1);

        }
        for(var row : map.entrySet())
        {
            System.out.printf("%c %d",row.getKey(),row.getValue());
        }

    }
}