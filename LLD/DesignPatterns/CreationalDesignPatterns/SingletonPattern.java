
class Product{
    private static  Product product;

   
    public static Product getInstance(){
        if(product == null){
            product = new Product();
        }
        return product;
    }

    
}


public class SingletonPattern {

    Product product = Product.getInstance();
}   
