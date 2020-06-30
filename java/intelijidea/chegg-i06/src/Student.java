import java.util.ArrayList;

public class Student {

    private int id;
    private String name;
    private ArrayList<Subject> subjects;
    private Semester currentSemester;
    private ArrayList<Semester> semesters;
    private int enrollmentNo;

    Student(int id, String name, Semester semester, int enrollmentNo){
        this.id = id;
        this.name = name;
        this.currentSemester = semester;
        this.semesters = new ArrayList<Semester>();
        this.subjects = new ArrayList<Subject>();
        this.enrollmentNo = enrollmentNo;
    }

    public int getId() {
        return id;
    }

    public Semester getSemester() {
        return this.currentSemester;
    }

    public String getName() {
        return name;
    }

    public void setSemester(Semester semester) {
        this.currentSemester = semester;
    }

    public ArrayList<Subject> getSubjects() {
        return subjects;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void addSubject(Subject subject){
        if(!this.hasSubject(subject.getId())){
            this.subjects.add(subject);
            return;
        }
        System.out.println("Given subject already exixts.");
    }

    public boolean hasSubject(int id){
        int i = 0;
        while (i<this.subjects.size()){
            if(this.subjects.get(i).getId() == id){
                return true;
            }
            i++;
        }
        return false;
    }

    public Subject getSubject(int id){
        int i = 0;
        while (i<this.subjects.size()){
            if(this.subjects.get(i).getId() == id){
                return this.subjects.get(i);
            }
            i++;
        }
        return null;
    }

    public void print(){
        System.out.println("id: "+this.getId());
        System.out.println("Name: "+this.name);
        System.out.println("Enrollment No.:"+ this.enrollmentNo);
        System.out.println("No. of subjects: "+ this.subjects.size());
        System.out.println();
        System.out.println();
    }
}
