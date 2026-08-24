import java.util.*;

interface IDevice
{
    public void turnOn();
    public void turnOff();
    
}

interface ICommand
{
    public void execute();
    
}

class Device1
{
    public void turnOn()
    {
        return;
    }
    
    public void turnOff()
    {
        return;
    }
    
    public void ChangeVolumn(){
        return;
    }
}

class Device1TurnOff implements ICommand
{
    private IDevice device;
    
    public Device1TurnOff(IDevice device){
        this.device = device;
    }
    
    @Override
    public void execute()
    {
        device.turnOff();
    }
}

class Remote
{
    public ICommand command; 
    
    public void setCommand(ICommand command)
    {
        
    }
}

class CommandClient
{
    
    public static void main(String[] args){
        
        
        return;    
    }
    
}