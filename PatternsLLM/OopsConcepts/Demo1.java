import java.lang.*;
abstract  class IStudent
{
    public abstract  void display();
}
public class Student extends IStudent
{
    public Integer id;
    public String name;

    Student(Integer id,String name)
    {
        this.id = id;
        this.name = name;
    }
    Student(Integer id)
    {
        this.id = id;
        this.name = "Default";
    }

    @Override
    public void display()
    {
        System.out.printf("%d %s",this.id,this.name);
    }

}

public class IIITDMStudent extends Student
{
    public String rollNo;

    IIITDMStudent(int id,String name,String rollNo)
    {
        super(id,name);
        this.rollNo = rollNo;
    }

    @Override
    public void display() {
        System.out.printf("%d %s %s",this.id,this.name,this.rollNo);
    }

}
public  class Demo1
{
    public static void main(String[] args)
    {
        Student student = new IIITDMStudent(1,"Rishi","CS21B1075");
        student.display();
    }

}