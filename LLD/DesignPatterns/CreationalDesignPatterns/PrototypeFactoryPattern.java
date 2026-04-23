
class Student implements Cloneable
{


    public Student clone() throws CloneNotSupportedException{
        return (Student) super.clone();
    }
}

public class PrototypeFactoryPattern {
    
    public static void main(String[] args){
            Student student = new Student();
    
    try
    {
        Student student1 = student.clone();
    }catch(Exception ex){
         ex.printStackTrace();
    }
    }
}
