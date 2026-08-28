import java.util.*;

interface IPatient
{
    public void accept(Visitor visitor);
}

class Patient1 implements IPatient
{
    @Override
    public void accept(Visitor visitor)
    {
        visitor.visit(this);
        return;
    }
}

class Patient2 implements IPatient
{
    @Override
    public void accept(Visitor visitor)
    {
        visitor.visit(this);
        return;
    }
}

interface IVisitor
{
    public void visit(Patient1 patient1);
    public void visit(Patient2 patient2);
}

class Visitor implements IVisitor
{
    @Override
    public void visit(Patient1 patient1){
        
        return;
    }
    
    @Override
    public void visit(Patient2 patient2){
        
        return;
    }
    
}


class CodeChef
{
    public static void main(String[] args){
        
        return;
    }
}