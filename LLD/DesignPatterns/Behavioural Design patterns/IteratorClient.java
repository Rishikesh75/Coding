import java.util.*;


interface IIterator<T>
{
    public boolean hasNext();
    
    public T next();
}


interface IAggregator<T>
{
    public IIterator<T> getIterator();
}

class SimpleIterator<Integer> implements IIterator<Integer>
{
    private List<Integer> list;
    int currIndex = -1;
    public SimpleIterator(List<Integer> list)
    {
        this.list = list;
    }
    
    @Override
    public boolean hasNext()
    {
        if(currIndex+1<list.size())  
            return true;
        
        else 
            return false;
    }
    
    @Override
    public Integer next()
    {
        return list.get(++currIndex);
    }
}

class SimpleAggregator<Integer> implements IAggregator<Integer>
{
    private List<Integer> list;
    
    public SimpleAggregator(List<Integer> list)
    {
        this.list = list;
    }
    
    @Override 
    public IIterator<Integer> getIterator()
    {
        return new SimpleIterator(list);
    }
}


class CodeChef
{
    public static void main(String[] args){
        
        List<Integer> list = new ArrayList<>(List.of(1,2,3,4));
        
        IAggregator<Integer> aggregrator = new SimpleAggregator(list);
        
        IIterator<Integer> it = aggregrator.getIterator();
        
        while(it.hasNext()){
            System.out.printf("%d",it.next());
            
        }
        
        return;
    }
}