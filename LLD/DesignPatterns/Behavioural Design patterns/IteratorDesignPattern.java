interface IIterator
{
    public boolean hasNext();
    public int next();
}

class CustomIterator implements IIterator
{
    public int[] arr;
    public boolean hasNext()
    {
        return true;
    }

    public int next()
    {
        return 1;
    }
}
class MyCollection
{
    

    public IIterator createIIterator()
    {

    }
}


public class IteratorDesignPattern {
    
}
