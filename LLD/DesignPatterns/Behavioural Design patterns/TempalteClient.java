import java.util.*;


abstract class Tempalate
{
    public void cook(){
        step1();
        step2();
    }
    
     public abstract void step1();
    
    public abstract void step2();
}


class Sample1 extends Tempalate
{
    @Override 
    public void step1()
    {
        return;
    }
    
    @Override
    public void step2()
    {
        
        return;
    }
}

class Sample2 extends Tempalate
{
    @Override
    public void step1()
    {
        
    }
    
    @Override
    public void step2()
    {
        
    }
    
}

class TemplateClient
{
    public static void main(String[] args){
        
        return;
    }
}