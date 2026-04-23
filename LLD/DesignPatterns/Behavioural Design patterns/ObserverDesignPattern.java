
import java.util.List;

interface IObserver
{

}

class Oberser implements IObserver
{

}

interface ISubject
{
    public void addOberserver(IObserver observer);
    public void removeObserver(IObserver observer);
    public void notifyAllObserver();
}

class Subject implements ISubject
{

    public List<IObserver> observer;
    public String state;
    public void addOberserver(IObserver observer){

    }

    public void removeObserver(IObserver observer){

    }

    public void notifyAllObserver()
    {

    }
}
public class ObserverDesignPattern {
    
}
