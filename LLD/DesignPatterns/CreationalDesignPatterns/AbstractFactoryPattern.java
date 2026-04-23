interface IProduct1
{

}

interface IProduct2
{

}

class Product1Type1 implements   IProduct1{

}


class Product1Type2 implements  IProduct1{

}

class Product2Type1 implements  IProduct2{

}

class Product2Type2 implements  IProduct2{

}

interface IFactory
{
    // IProduct1 createProduct1();
    // IProduct2 createProduct2();
}

class Factory1 implements IFactory
{

}

class Factory2 implements IFactory
{
    
}



public class AbstractFactoryPattern
{
    public static void main(String[] args){
        return;
    }
}