import java.util.*;
import java.lang.*;
import java.io.*;


interface IStratergy
{
    public void performTask();
}

class Stratergy1 implements IStratergy
{
    @Override
    public void performTask()
    {
        
    }
}

class Stratergy2 implements IStratergy
{
    @Override
    public void performTask()
    {
        
    }   
}


class Stratergy3 implements IStratergy
{
    @Override
    public void performTask()
    {
        
    }
}

class Context
{
    private IStratergy stratergy;
    
    public void setStratergy(IStratergy stratergy){
        
    }
    
    public Context(IStratergy stratergy){
        this.stratergy = stratergy;
    }
    
    public void performTask(){
        stratergy.performTask();
    }
    
}
class StratergyClient
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Context context = new Context(new Stratergy1());
		
		context.setStratergy(new Stratergy2());
		
		context.performTask();

	}
}
