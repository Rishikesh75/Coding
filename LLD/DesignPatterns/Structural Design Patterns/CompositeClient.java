import java.util.*;
import java.lang.*;
import java.io.*;

interface IItem
{
    
}

class File implements IItem
{
    
}

class Folder implements IItem
{
    private List<IItem> children = new ArrayList<>();
    
    public void addItem(IItem item){
        children.add(item);
    }
    
    public void removeItem(IItem item){
        children.remove(item);
    } 
    
    public IItem getItem(int index){
        return children.get(index);
    }
}


class CompositeClient
{
	public static void main (String[] args) throws java.lang.Exception
	{
    
        Folder folder = new Folder();
        
        folder.addItem(new Folder());
        folder.addItem(new File());
        
        folder.removeItem(folder.getItem(1));
        
	}
}
