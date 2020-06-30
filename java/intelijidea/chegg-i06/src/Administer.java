import java.util.ArrayList;

public class Administer {

    private ArrayList<Student> students;
    private int id;
    private String name;

    Administer(int id, String name){
        this.id = id;
        this.name = name;
        this.students = new ArrayList<Student>();
    }

    public void addStudent(Student student){
        if(!this.hasStudent(student.getId())){
            this.students.add(student);
            return;
        }
        System.out.println("Given student already exists.");
    }

    public boolean hasStudent(int id){
        int i = 0;
        while (i<this.students.size()){
            if(this.students.get(i).getId() == id){
                return true;
            }
            i++;
        }
        return false;
    }

    public Student getStudent(int id){
        int i = 0;
        while (i<this.students.size()){
            if(this.students.get(i).getId() == id){
                return this.students.get(i);
            }
            i++;
        }
        return null;
    }

    public void print(){
        System.out.println("Id: "+this.id);
        System.out.println("Name: "+this.name);
        System.out.println("No. of students: "+this.students.size());
        System.out.println();
        System.out.println();
    }

}
