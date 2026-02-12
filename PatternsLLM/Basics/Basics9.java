public class Basics9
{
    public static boolean Isprime(int n){
        for(int i=2;i<n;i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }

    public static int findFactorial(int n){
        int val = 1;
        for(int i=1;i<=n;i++){
            val = val * i;
        }
        return val;
    }

    public static int findMax(int a1,int a2,int a3){
        if(a1>a2){
            if(a1>a3) return a1;
            else return a3;
        }
        else{
            if(a2>a3) return a2;
            else return a3;
        }
    }

    public static int addition(int a1,int a2){
        return a1+a2;
    }

    public static double addition(double a1,double a2){
        return a1+a2;
    }

    public static void main(String[] args){
        System.out.printf("Booleann:%b\n",Isprime(4));
        System.out.printf("factorial:%d\n",findFactorial(2));
        System.out.printf("max:%d\n",findMax(1,2,3));
        System.out.printf("additionInt:%d additionDouble:%f",addition(1,2),addition(1.1,1.2));
    }
}