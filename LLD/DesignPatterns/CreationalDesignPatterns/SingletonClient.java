import java.util.*;


// Singleton
class Singleton
{
    private static SingletonClient instance;
    
    public SingletonMain(){
        if(instance != null){
            instance =  new SingletonClient();
        }
    }
    
    public SingletonClient getInstance()
    {
        return instance;
    }
}
class SingletonClient
{
    public static void main(String[] args){
        
        SingletonClient singleton1 = new SingletonClient().getInstance();
        SingletonClient singleton2 = new SingletonClient().getInstance();
        
        if(singleton1 == singleton2){
            System.out.println("Singleton Instance...");
        }
        else{
            System.out.println("Error Singleton Instance...");
        }
        return;
    }
}