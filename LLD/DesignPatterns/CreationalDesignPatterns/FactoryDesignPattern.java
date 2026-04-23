enum ProductType{
    A,B
}

interface IProduct{

}

class ProductA implements IProduct{

}

class ProductB implements  IProduct{

}

interface  IFactory{

    public IProduct createProduct(ProductType type);
}

class Factory implements  IFactory{

    @Override
    public IProduct createProduct(ProductType type){
        if(type == ProductType.A){
            return new ProductA();
        }

        return new ProductB();
    }
}

public class FactoryDesignPattern {
    

    public static void main(String[] args) {
        
        IFactory factory = new Factory();
        IProduct product = factory.createProduct(ProductType.A);

        return;
    }
}
