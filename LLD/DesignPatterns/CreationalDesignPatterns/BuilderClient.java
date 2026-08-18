import java.util.*;
import java.util.Scanner;

class Product{
    
    public int id;
    public String name;
    public String deliveryAddress;
    
    Product(int id,String name,String deliveryAddress){
        this.id = id;
        this.name = name;
        this.deliveryAddress = deliveryAddress;
    }
    static class Builder{
            public int id;
            public String name;
            public String deliveryAddress;
            
            public Builder buildId(int id){
                this.id = id;
                return this;
            }
            
            public Builder buildName(String name){
                this.name = name;
                return this;
            }
            
            public Builder BuildDeliveryAddress(String name){
                this.deliveryAddress = deliveryAddress;
                return this;
            }
            
            public Product build(){
                return new Product(id,name,deliveryAddress);
            }
        }
    
}


class BuilderClient
{
    public static void main(String[] args){
        
        Product product1 = new Product.Builder().buildId(1).
                            buildName("Sample").BuildDeliveryAddress("dfjasljf").build();
        
        
        return;
    }
}