

class Animal implements   IAnimal
{
    Animal()
    {

    }

}
class Dog extends Animal
{
    Dog()
    {
        super();
    }
}
interface  IAnimal
{

}
abstract class sample
{
    public abstract void display();
    
}
class Basics1 {
    
    public  static class Student
    {
        public String name;

        public String rollno;

        public int marks;

        public static int count = 0;

        public Student(String name,String rollno,int marks)
        {
            this.name = name;
            this.rollno = rollno;
            this.marks = marks;
            this.count++;
        }

        public Student(String name)
        {
            this.name = name;
            this.rollno = "";
            this.marks = 0;
        }

        public Student(Student st)
        {
            this.name = st.name;
            this.rollno = st.rollno;
            this.marks = st.marks;
        }

        @Override
        public String toString()
        {
            StringBuilder sb = new StringBuilder();

            sb.append("Name: ").append(name);
            sb.append("RollNo: ").append(rollno);
            sb.append("Marks: ").append(marks);
            return sb.toString();
        }

        public void rename(String name,int marks)
        {
            return;
        }

        public void change(String name)
        {

            return;
        }
    }

    public static void main(String[] args) {
        
        Student student = new Student("rishi","cs21b1075", 0);

        System.out.printf("%s",student.toString());

        return;
    }
}
