import java.util.*;

interface IState
{
    
    public void execute();
}

class State1 implements IState
{
    public void execute()
    {
        
    }
    
}

class State2 implements IState
{
    
    public void execute()
    {
        
    }
    
}

class Device
{
    private IState state;
    
    public void setState(IState state)
    {
        
    }
    
    public void execute()
    {
        state.execute();
    }
}
class StateClient
{
    
    public static void main(String[] args){
        
        
        return;    
    }
    
}