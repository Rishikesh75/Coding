import java.util.*;
import java.lang.*;


interface IProduct
{
    
}

class ProductA implements IProduct
{
    
    
}

interface IFactory
{
    public IProduct createNewProduct();
}

class FactoryA implements IFactory
{
    @Override
    public IProduct createNewProduct(){
        return new ProductA();
    }
}

class FactoryClient
{
    public static void main(String[] args){
        IFactory factoryA = new FactoryA();
        IProduct productA = factoryA.createNewProduct();
    }
}