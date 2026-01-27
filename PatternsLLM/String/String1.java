import java.util.*;
public class String1
{
    public static void reverseString(String s)
    {
        StringBuilder sb = new StringBuilder(s);
        int i=0;
        int j = sb.length()-1;
        while(i<j)
        {
            char temp = sb.charAt(i);
            sb.setCharAt(i,sb.charAt(j));
            sb.setCharAt(j,temp);
            i = i + 1;
            j = j - 1;
        }
        System.out.printf("%s\n",sb.toString());

    }
    public static void  checkStringPalindrome(String s)
    {
        StringBuilder sb = new StringBuilder(s);
        if(s.equals(sb.reverse().toString())) System.out.print("yes\n");
        else System.out.println("No\n");
        return;
    }
    public static void countVCDS(String s)
    {
        Map<Character,Integer>mp = new HashMap<>();
        StringBuilder sb = new StringBuilder(s);
        for(int i=0;i<sb.length();i++)
        {
            Character c = sb.charAt(i);

            if(c == 'a' || c == 'o' || c == 'e' || c== 'i' || c== 'u') c = 'v';
            else if( c >='1' && c<='9')c = 'd';
            else if(c == ' ') c = 's';
            else c = 'c';

            if(mp.containsKey(c))
                mp.replace(c,mp.get(c)+1);
            else
                mp.put(c,1);
        }
        for(var kvp : mp.entrySet())
        {
            System.out.printf("%c %d\n",kvp.getKey(),kvp.getValue());
        }
    }
    public static int NoofWords(String s)
    {
        StringBuilder sb = new StringBuilder(s);
        int count = 1;
        for(int i=0;i<sb.length();i++)
        {
            if(sb.charAt(i) == ' ')
            {
                count = count + 1;
            }
        }
        return count;
    }
    public static String removeDuplicateChar(String s)
    {
        StringBuilder sb = new StringBuilder(s);
        Set<Character> set = new LinkedHashSet<>();

        for(int i=0;i<sb.length();i++)
        {
            set.add(sb.charAt(i));
        }
        sb.setLength(0);
        for(var ch : set)
        {
            sb.append(ch);
        }
        return sb.toString();
    }
    public static Character firstNonRepetetingChar(String s)
    {
        StringBuilder sb = new StringBuilder(s);
        Map<Character,Integer>mp = new LinkedHashMap<>();
        for(int i=0;i<sb.length();i++)
        {
            mp.put(sb.charAt(i),mp.getOrDefault(sb.charAt(i),0)+1);
        }
        for(var kvp : mp.entrySet())
        {
            if(kvp.getValue() == 1)
            {
                return kvp.getKey();
            }
        }
        return ' ';
    }
    public static String replaceString(String s)
    {
        StringBuilder sb = new StringBuilder(s);
        for(int i=0;i<sb.length();i++)
        {
            if(sb.charAt(i) == ' ')
            {
                sb.setCharAt(i,'-');
            }
        }
        return sb.toString();
    }
    public static void main(String[] args)
    {
        reverseString("HelloooWorld");
        checkStringPalindrome("aba");
        countVCDS("hi this is rishi");
        System.out.printf("No of Words %d",NoofWords("hi this is Rishi"));
        System.out.printf("Output: %s",removeDuplicateChar("hiiiii"));
        System.out.printf("Output: %c",firstNonRepetetingChar("aaaabbbbccd"));
        System.out.printf("Ouput: %s",replaceString("hi this is Rishi"));
    }
}