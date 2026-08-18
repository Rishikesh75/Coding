import java.util.*;



interface IClonable
{
    public Object clone();
}

class Product implements IClonable
{
    @Override 
    public Object clone()
    {
        return new Product();
    }
}
class PrototypeClient
{
    public static void main(String[] args){
        
        
        Product product1 = new Product();
        Product product2 = (Product)product1.clone();
        return;
    }
}