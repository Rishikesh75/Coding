import java.util.*;
import java.lang.*;
import java.io.*;



interface IProductA{
    
}

interface IProductB{
    
}

interface IFactory
{
    public IProductA createProductA();
    public IProductB createProductB();
}


class ProductA1 implements IProductA
{
    
}

class ProductA2 implements IProductA
{
    
}

class ProductB1 implements IProductB
{
    
}

class ProductB2 implements IProductB{
    
}

class Factory1 implements IFactory
{
    @Override 
    public IProductA createProductA()
    {
        return new ProductA1();
    }
    
    @Override
    public IProductB createProductB()
    {
        return new ProductB1();
    }
}

class Factory2 implements IFactory
{
    @Override
    public IProductA createProductA(){
        return new ProductA2();
    }
    
    @Override 
    public IProductB createProductB(){
        return new ProductB2();
    }
}


class AbstractFactoryClient
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Factory1 factory1 = new Factory1();
		Factory2 factory2 = new Factory2();
		
		factory1.createProductA();
		factory2.createProductA();
		
		factory1.createProductA();
		factory2.createProductB();

	}
}
