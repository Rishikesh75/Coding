





class Student
{
    public int rolllNo;

    public String name;

    public Student(BuilderStudent builderStudent){
        this.rolllNo = builderStudent.rolllNo;
        this.name = builderStudent.name;
    }

    public static class BuilderStudent
    {
        public int rolllNo;

        public String name;

        public BuilderStudent setRollNo(int rollNo){
            this.rolllNo = rollNo;
            return this;
        }

        public BuilderStudent setName(String name){
            this.name = name;
            return this;
        }

        public Student build()
        {
            return new Student(this);
        }

    }

    
}



public class BuilderDesignPattern{
    
    
    
    public static void main(String[] args){

            Student student = new Student.BuilderStudent()
                                .setRollNo(1)
                                .setName("Rishi").build();
    }
}