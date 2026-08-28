import java.util.*;


class TextEditor
{
    private String text;
    
    
    public TextEditor(String text)
    {
        this.text = text;
        
    }
    
    public Memento save(String text)
    {
       return new Memento(text);
    }
    
    public void restore(Memento memento)
    {
        this.text = memento.getText();
    }
}

class Memento
{
    private final String text;
    
    Memento(String text)
    {
        this.text = text;
    }
    
    public String getText()
    {
        return this.text;
    }
}
class MementoClient{
    public static void main(String[] args)
    {
        
        return;
    }
}
