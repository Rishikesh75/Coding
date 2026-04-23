

public class S1
{
    
    public static class FrequencyClass
    {
        public int vowelCount;
        public int consonenetCount;

        public FrequencyClass(int v1,int v2)
        {
            this.vowelCount = v1;
            this.consonenetCount = v2;
        }
    }
    public static String reverseString(String s)
    {
        StringBuilder sb = new StringBuilder(s);

        int i= 0;
        int j = s.length()-1;

        while(i<j)
        {
            char temp = sb.charAt(i);
            sb.setCharAt(i, sb.charAt(j));
            sb.setCharAt(j, temp);
        }

        return sb.toString();
    }

    public static boolean isPlaindrome(String s)
    {
        StringBuilder sb = new StringBuilder(s);
        
        int i = 0;
        int j = s.length()-1;

        while(i<j)
        {
            if(sb.charAt(i) != sb.charAt(j))
            {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    public static FrequencyClass countVowelsAndConsonents(String s)
    {
        StringBuilder sb = new StringBuilder(s);
        
        FrequencyClass fc = new FrequencyClass(0, 0);
        
        for(int i = 0;i<sb.length();i++)
        {
            if(sb.charAt(i) == 'a' || sb.charAt(i) =='e' || sb.charAt(i) == 'i' || sb.charAt(i) == 'o' || sb.charAt(i) =='u'){
                fc.vowelCount++;
            }
            else
                fc.consonenetCount++;
        }

        return fc;
    }

    public static boolean isAnagram(String s1,String s2)
    {
        int[] arr = new int[26];

        for(int i = 0;i<s1.length();i++)
        {
            int num = s1.charAt(i) - 'a';
            arr[num]++;
        }

        for(int i=0;i<s2.length();i++)
        {
            int num = s2.charAt(i) - 'a';
            arr[num]--;
        }

        for(var val : arr)
        {
            if(val!=0)
                return false;
        }

        return true;
    }

    public static String removeSpaces(String s)
    {

        StringBuilder sb = new StringBuilder(s);

        for(int i=s.length()-1;i>=0;i--)
        {
            if(sb.charAt(i) == ' ')
            {
                sb.deleteCharAt(i);
            }

        }
        
        return "";
    }
    
    public static String findDuplicateCharacter(String s)
    {
        int[] arr = new int[26];

        for(char c : s.toCharArray())
        {
            arr[(c-'a')]++;
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < 26; i++) {
        if (arr[i] > 1) {
            sb.append((char)('a' + i));
        }
        }

        return sb.toString();
    }


    
    public static void main(String[] args) {
        
    }
}